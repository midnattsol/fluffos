# FluffOS agent guide

FluffOS is an LPMUD driver in C++. `testsuite/` is its LPC harness, not a starter mudlib.

Build: `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo && ninja -C build driver` gives `build/src/driver`.
Test, from `testsuite/`: `../build/src/driver etc/config.test -ftest[:single/tests/efuns/foo.lpc]`. A pass needs `Checks succeeded.`, exit 0 read without a pipe, and no `^\]\*.*Check failed` in the log.

## Rules
- `error()` is a C++ throw: cleanup after anything that can error never runs, so use RAII or `DEFER`.
- A copied compound pointer needs `ref++`; free raw malloced strings with `FREE_MSTR`, never `FREE`.
- Never pass untrusted text as a printf format to `error()`, `yyerror` or similar.
- Do not hand-edit `*.autogen.*` or generated docs.
- A memory-safety fix needs a test that fails on the unfixed binary, run on Debug+ASan and RelWithDebInfo.
- Top-level agents delegate broad searches to `explorer` and clear briefs to `implementer`, review its diff, and never delegate design, hard debugging or memory-safety review.

## Read before touching (all in `agent-guides/`)
- Layout of the tree: `architecture.md`
- Efuns, packages, includes: `packages.md`
- Refcounts, svalues, error paths: `memory.md`
- Auditing or fixing memory bugs: `memory-audit.md`
- CMake, CI, WASM, or any Windows or WSL host: `build-ci.md` first
- Writing or debugging tests: `testsuite.md`
- VM, types, applies, hot reload: `lpc-runtime.md`
- Lexer, parser, compiler: `compiler.md`
- `docs/`: `docs-site.md`
- `src/thirdparty/`: `thirdparty.md`
