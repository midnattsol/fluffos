#include "base/std.h"

#include <gtest/gtest.h>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace {
class RuntimeConfig : public testing::Test {
 protected:
  std::filesystem::path directory;

  void SetUp() override {
    directory = std::filesystem::temp_directory_path() /
                ("fluffos-config-" + std::to_string(
                    std::chrono::steady_clock::now().time_since_epoch().count()));
    std::filesystem::create_directory(directory);
  }
  void TearDown() override { std::filesystem::remove_all(directory); }

  std::string write(const char* name, const std::string& text) {
    auto path = directory / name;
    std::ofstream(path) << text;
    return path.string();
  }

  const std::string minimal = R"(
name = "Example"
mudlib_directory = "./lib"
log_directory = "log"
include_directories = ["/include", "/secure/include"]
master_file = "/secure/master.lpc"
debug_log_file = "debug.log"
)";
};

// read_config is a process-startup API and exits on invalid input. Each check
// runs in a child without initializing the VM or opening network listeners.
TEST_F(RuntimeConfig, TomlAndLegacyHaveEquivalentRuntimeSettings) {
  auto legacy = write("config.rc", R"(
name : Example
mudlib directory : ./lib
log directory : log
include directories : /include:/secure/include
master file : /secure/master.lpc
debug log file : debug.log
global include file : <global.h>
simulated efun file : /secure/simul.lpc
maximum array size : 64000
enable gmcp : 1
default fail message : Huh?
external_port_1 : telnet 3333
external_port_2 : websocket 8080
external_port_2_tls : cert=cert.pem key=key.pem
websocket http dir : www
)");
  auto toml = write("config.toml", minimal + R"(
global_include_file = "<global.h>"
simulated_efun_file = "/secure/simul.lpc"
maximum_array_size = 64000
enable_gmcp = true
default_fail_message = "Huh?"
websocket_http_dir = "www"
[[ports]]
type = "telnet"
port = 3333
[[ports]]
type = "websocket"
port = 8080
tls_cert = "cert.pem"
tls_key = "key.pem"
)");
  ASSERT_EXIT({
    read_config(legacy.c_str());
    std::vector<int> integers(std::begin(config_int), std::end(config_int));
    std::vector<std::string> strings(std::begin(config_str), std::end(config_str));
    const auto first = external_port[0];
    const auto second = external_port[1];
    read_config(toml.c_str());
    bool equal = integers == std::vector<int>(std::begin(config_int), std::end(config_int)) &&
                 strings == std::vector<std::string>(std::begin(config_str), std::end(config_str)) &&
                 first.kind == external_port[0].kind && first.port == external_port[0].port &&
                 second.kind == external_port[1].kind && second.port == external_port[1].port &&
                 second.tls_cert == external_port[1].tls_cert &&
                 second.tls_key == external_port[1].tls_key;
    std::_Exit(equal ? 0 : 1);
  }, testing::ExitedWithCode(0), "");
}

TEST_F(RuntimeConfig, PreservesHashesEscapesUnicodeAndLongStrings) {
  std::string long_value(300, 'x');
  auto path = write("config.toml", minimal +
      "default_error_message = \"cámara # text \\\"quoted\\\" " + long_value + "\"\n" +
      "default_fail_message = \"What?\\n\"\nport_number = 3333\n");
  ASSERT_EXIT({
    read_config(path.c_str());
    std::string expected = "cámara # text \"quoted\" " + long_value;
    std::_Exit(expected == CONFIG_STR(__DEFAULT_ERROR_MESSAGE__) &&
               std::string(CONFIG_STR(__DEFAULT_FAIL_MESSAGE__)) == "What?\n" &&
               CONFIG_INT(__MUD_PORT__) == 3333 && external_port[0].port == 3333 ? 0 : 1);
  }, testing::ExitedWithCode(0), "");
}

TEST_F(RuntimeConfig, RejectsMalformedUnknownAndMistypedOptions) {
  const std::vector<std::string> invalid = {
      "unknown_option = 1", "maximum_array_size = -1", "maximum_array_size = 999999999999",
      "maximum_array_size = 1.5", "maximum_array_size = '64000'", "ports = 'telnet'",
      "hash_table_size = true",
      "port_number = 65536", "port_number = true", "default_error_message = 42",
      "[unexpected_table]\nx = 1", "name = 'duplicate'", "value = [",
      "[[ports]]\ntype = 'telnet'\nport = 0", "[[ports]]\ntype = 'invalid'\nport = 1234",
      "[[ports]]\ntype = 'telnet'\nport = 1234\ntls_cert = 'cert.pem'",
      "[[ports]]\ntype = 'telnet'\nport = 1234\ntls_cert = ''\ntls_key = ''",
      "[[ports]]\ntype = 'telnet'\nport = 1234\nprot = 5555",
      "port_number = 3333\n[[ports]]\ntype = 'telnet'\nport = 4444",
      "default_error_message = \"\\u0000\""
  };
  for (const auto& extra : invalid) {
    SCOPED_TRACE(extra);
    auto path = write("bad.toml", minimal + extra + "\n");
    ASSERT_EXIT(read_config(path.c_str()), testing::ExitedWithCode(EXIT_FAILURE), "Error in TOML config");
  }
}

TEST_F(RuntimeConfig, RejectsMissingRequiredSettingsAndExcessPorts) {
  auto missing = write("missing.toml", "name = 'Example'\n");
  ASSERT_EXIT(read_config(missing.c_str()), testing::ExitedWithCode(EXIT_FAILURE), "missing required");
  std::string many = minimal;
  for (int i = 0; i < 6; ++i) many += "[[ports]]\ntype = 'telnet'\nport = " + std::to_string(3333+i) + "\n";
  auto excess = write("excess.toml", many);
  ASSERT_EXIT(read_config(excess.c_str()), testing::ExitedWithCode(EXIT_FAILURE), "at most five");
}

TEST_F(RuntimeConfig, ValidatesIncludeArrayElements) {
  for (const std::string replacement : {"[42]", "['']", "['/one:/two']", "[]"}) {
    auto text = minimal;
    const std::string original = "[\"/include\", \"/secure/include\"]";
    text.replace(text.find(original), original.size(), replacement);
    auto path = write("include.toml", text);
    ASSERT_EXIT(read_config(path.c_str()), testing::ExitedWithCode(EXIT_FAILURE), "include_directories");
  }
}

#ifdef PACKAGE_EXTERNAL
TEST_F(RuntimeConfig, ExternalCommandArrayUsesOneBasedSlots) {
  auto path = write("external.toml", minimal + "external_commands = ['/usr/bin/helper', '/path with spaces/helper']\n");
  ASSERT_EXIT({
    read_config(path.c_str());
    std::_Exit(external_cmd[0] && external_cmd[1] && !external_cmd[2] &&
               std::string(external_cmd[0]) == "/usr/bin/helper" &&
               std::string(external_cmd[1]) == "/path with spaces/helper" ? 0 : 1);
  }, testing::ExitedWithCode(0), "");
}
#endif
}  // namespace
