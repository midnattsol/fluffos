# FluffOS architecture and key components

Welcome to FluffOS. This guide provides future AI coding agents with essential codebase information, architecture context, Package API standards, and Continuous Integration setup.

## Codebase Architecture & Key Components

FluffOS is a high-performance LPMUD driver and game engine. Its codebase is structured as follows:

* **`src/`**: Core driver and event dispatcher.
  - `mainlib.cc`: Engine initialization.
  - `backend.cc`: The gametick/event queues (event-loop-agnostic core); `backend_libevent.cc` is the native blocking loop, `wasm/backend_wasm.cc` the host-driven WASM loop.
  - `comm.cc`: Transport-agnostic connection handling (users, command queue, input_to, prompts, snoop). It talks to sockets only through the `Transport` interface (`net/transport.h`).
  - `net/`: The byte-transport layer -- `transport_libevent.cc` (bufferevent/TLS/websocket transports + listening ports + socket reads), `telnet.cc` (protocol, portable), `net_compat.h` (platform type decls).
  - `user.cc`: Connection session states.
  - `wasm/`: WebAssembly target files (JS transport, exported entry points, crash-handler stub).
* **`src/vm/`**: The execution VM and LPC bytecode interpreter.
  - `interpret.cc`: The core bytecode interpreter loop (`eval_instruction`).
  - `simulate.cc`: Object loading, cloning, destruction, and simulation event loops; also `recompile_object()` (in-place program update: recompiles a source file and swaps the program into the live master copy and all clones, carrying variables over by name -- see docs/concepts/general/hot_reload.md).
  - `vm.cc`: VM startup and master object callbacks.
* **`src/compiler/`**: The LPC parser, compiler, and code generator.
  - `grammar.y` / `grammar.autogen.cc`: Bison rules compiling LPC scripts to bytecode.
  - `lexer.l` / `generate.cc`: Lexer and VM instructions generator.
* **`src/packages/`**: Modular packages implementing C++ external functions (efuns). `packages/jsbridge/` (WASM target only) is the LPC <-> page-JavaScript bridge: `js_eval`/`js_call` outbound, `js_export` + the page's `fluffos.callLPC()` inbound; async deliveries run on the next tick and the pending tables hold/mark refs like the resolve() efun.
* **`testsuite/`**: Core LPC test cases, std library objects, and configurations (see `testsuite/README.md`). LPC sources use the `.lpc` extension; the driver resolves an explicit `.c`/`.lpc` exactly and prefers `.lpc` (falling back to `.c`) for extension-less names — pinned by `testsuite/single/tests/efuns/dual_extension.lpc`.
