#include "base/std.h"

#include <gtest/gtest.h>

#include <vector>

#include "net/telnet.h"
#include "thirdparty/libtelnet/libtelnet.h"

namespace {

void capture_send(telnet_t*, telnet_event_t* event, void* user_data) {
  if (event->type != TELNET_EV_SEND) {
    return;
  }

  auto* output = static_cast<std::vector<unsigned char>*>(user_data);
  output->insert(output->end(), event->data.buffer, event->data.buffer + event->data.size);
}

TEST(TelnetTerminalType, RequestIsACompleteSubnegotiation) {
  static const telnet_telopt_t telopts[] = {{-1, 0, 0}};
  std::vector<unsigned char> output;
  telnet_t* telnet = telnet_init(telopts, capture_send, 0, &output);
  ASSERT_NE(nullptr, telnet);

  telnet_request_ttype(telnet);
  telnet_free(telnet);

  const std::vector<unsigned char> expected = {
      TELNET_IAC, TELNET_SB, TELNET_TELOPT_TTYPE, TELNET_TTYPE_SEND, TELNET_IAC, TELNET_SE};
  EXPECT_EQ(expected, output);
}

}  // namespace
