---
title: cli / driver
---
# cli / driver

`driver` is the main binary produced from FluffOS Project.

## Usage

```bash
./driver [flags] config_file
```

## Configuration files

Files ending in `.toml` use TOML 1.0. Other filenames keep the traditional
`key : value` format. The shared configuration reader supports TOML in `driver`,
`lpcc`, and `lpcshell`.

```bash
./driver config.toml
./lpcc config.toml /cmds/creator/ls.c
```

TOML option names are the names in the [configuration reference](../driver/config)
with spaces replaced by underscores and ASCII letters lowercased. Defaults,
required settings, integer bounds, and path meanings are unchanged. In particular,
a relative `mudlib_directory` is relative to the **process working directory**,
not the configuration file. Keys containing punctuation must be quoted, for
example `"call_out(0)_nest_level" = 1000`.

```toml
name = "My MUD"
mudlib_directory = "../mudlib"
log_directory = "log"
debug_log_file = "debug.log"
master_file = "/secure/master.c"
simulated_efun_file = "/secure/simul_efun.c"
global_include_file = "<standard.h>"
include_directories = ["/include", "/secure/include"]

maximum_evaluation_cost = 30000000
maximum_array_size = 64000
enable_gmcp = true

[[ports]]
type = "telnet"
port = 3333

[[ports]]
type = "websocket"
port = 8080
# tls_cert = "cert.pem"
# tls_key = "key.pem"
```

- String options use TOML strings; `#` inside a string is preserved. There is
  no legacy 120-character line limit. NUL bytes are rejected.
- Integer settings also accept `true`/`false` as `1`/`0`. Out-of-range values
  are errors in TOML, rather than being reset to defaults as in the legacy reader.
- `include_directories` accepts either an array of nonempty paths or the legacy
  colon-separated string. Array entries cannot contain `:`.
- `ports` accepts up to five tables. Types are `telnet`, `websocket`, `ascii`,
  `binary`, and `mud`; port numbers are 1–65535. Supply `tls_cert` and `tls_key`
  together. `websocket_http_dir` is a top-level string.
- For a single Telnet listener, `port_number = 3333` is also supported. It cannot
  be combined with `ports`.
- With `PACKAGE_EXTERNAL`, `external_commands = ["/path/to/program"]` assigns
  command slots starting at 1. The build's external-command limit applies.
- Unknown keys, duplicate keys and invalid types are errors. Legacy numbered
  keys such as `external_port_1` are represented by `ports` tables in TOML.

A starting file is available as `config.example.toml` in the repository root.
`--generate-config` continues to emit the traditional format.

## Flags

| Flag                     | Description                                                                                                               |
|--------------------------|---------------------------------------------------------------------------------------------------------------------------|
| `-f<flag>`               | After initialization, before opening network connections, driver will call `void flag(string)` function on master object. |
| `-d<category>`           | Enable debug logging, this flag can occur multiple times. This is same as calling `set_debug_level()` EFUN.               |
| `--tracing <trace_file>` | Enable LPC tracing                                                                                                        |
| `--generate-config`      | Print a starter config file (all options, with defaults and comments) to stdout and exit. Redirect to a file to use it.  |

## Debug logging Categories

| Category        | Description                          |
|-----------------|--------------------------------------|
| `call_out`      | Callouts                             |
| `d_flag`        | Legacy combination of various events |
| `connections`   | external connections                 |
| `mapping`       | Mapping operations                   |
| `sockets`       | LPC Sockets related logs             |
| `comp_func_tab` | Compilation                          |
| `LPC`           | LPC execution                        |
| `LPC_line`      | LPC execution                        |
| `event`         | Events                               |
| `dns`           | DNS resolution logs                  |
| `file`          | Filesystem operations                |
| `add_action`    | add_action packages related logs     |
| `telnet`        | Telnet protocol                      |
| `websocket`     | Websocket protocol                   |
