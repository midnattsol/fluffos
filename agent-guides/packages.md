# Packages, efuns and header inclusion

## Package API & VM Stack Guidance

When creating or modifying packages (efuns) under `src/packages/`, you must follow these rules:

### Unified Inclusion
* All package source files **must** include `"base/package_api.h"` as their first header. Avoid importing VM, interpreter, or compiler headers directly.

### Spec Files
* Package functions are declared in `[package_name].spec` files using LPC-like syntax, e.g.:
  `int db_close(int);`
  The `make_func` parser compiler compiles these specs into C++ glue code (`efuns.autogen.cc`).

### VM Stack & Argument Unpacking
LPC arguments and return values are passed on the VM evaluation stack using `svalue_t` structures. The stack pointer is `sp`.

#### Navigating the Stack:
* The last argument is at `sp`. The first argument is at `sp - (num_args - 1)`.
* For variable-argument functions, the number of arguments passed is available via the global `st_num_arg`.

#### Accessing Arguments:
* `sp->u.number` or `(sp - n)->u.number`: Accessing integer values.
* `sp->u.string` or `(sp - n)->u.string`: Accessing string values.
* `sp->u.real` or `(sp - n)->u.real`: Accessing float/real values.
* `sp->u.arr`: Accessing arrays (`array_t *`).
* `sp->u.map`: Accessing mappings (`mapping_t *`).
* `sp->u.buf`: Accessing buffers (`buffer_t *`).

#### Modifying the Stack & Returning Values:
* Use `pop_stack()` or `pop_n_elems(n)` to clean up input arguments.
* Push return values to the stack:
  - `push_number(val)` / `push_real(val)`
  - `push_malloced_string(str)` / `push_constant_string(str)`
  - `put_malloced_string(str)` / `put_array(arr)` / `put_mapping(map)` (these replace the top stack element directly).

### Generic Argument Type-Checking (don't re-implement it)
* The VM's efun dispatch opcodes (`F_EFUN1`/`F_EFUN2`/`F_EFUN3` for fixed arity, `F_EFUNV` walking `efun_arg_etypes[]`) call `CHECK_TYPES()`/`bad_argument_multiple_types()` **before your efun's C function ever runs**, checked against the type(s) declared for that argument in the `.spec` file. For any argument whose spec type is a scalar/reference type or a union of them (`string`, `int`, `buffer`, `object`, `function`, `array`, `mapping`, or an `|` of these), **the top-level `svalue_t.type` tag is already validated** -- a hand-written `if (sp->type != T_STRING) error(...)` duplicating that is dead code, not a fix, even though a mudlib call site used a `mixed` variable to dodge the compiler's static `strict_types` check.
* This mechanism can only see the top-level type tag, so it **cannot** validate the ELEMENTS of a compound argument -- `array_t`/`mapping_t` carry no per-element type info at the svalue level. A spec of `string *names` gets zero element-type enforcement for free; per-element checks (each array item's `.type`) are a real, common gap (see `matrix.cc`'s per-cell check, `socket_write()`'s T_ARRAY branch). When auditing a "missing type check" finding, test it empirically on the *unfixed* binary first (a probe LPC call with a bad-typed argument) -- if the generic dispatch already produces a clean `Bad argument N to efun() Expected: ... Got: ...` error, the finding is a false positive; only element-level or varargs-position checks are usually the real gap.

## Header Inclusion Guidelines

To maintain code health and consistency, FluffOS enforces the following global include rules:

* **First Include ("base/std.h")**: All code files in the driver (excluding files in `src/base/` and package implementations in `src/packages/`) **must** include `"base/std.h"` as their very first line, followed by a blank line to clearly separate it from other includes.
* **No Other Base Includes**: Other headers inside `src/base/` should not be included directly. Headers inside `src/base/internal/` must include necessary dependencies themselves.
* **Package Include ("base/package_api.h")**: All package source files must include `"base/package_api.h"` as their first header, and **must not** include `"base/std.h"` again.
