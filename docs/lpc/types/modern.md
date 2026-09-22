---
title: types / modern values and errors
---
# Modern values and errors

Opt in per program with `#pragma modern_types`. Without this pragma the new
words remain available as legacy identifiers and `catch` retains its historical
return convention. Native JSON and error efuns are available in either mode.

## Values

```c
#pragma strict_types
#pragma modern_types

bool enabled = true;
null_value empty = null;
error_value failure = make_error("data.invalid", "Invalid profile");
```

`false`, `null`, integer zero, and an undefined mapping lookup are distinct.
False and null are false in conditions. Boolean arithmetic requires an explicit
application-level conversion; booleans are not integers. Use `booleanp()` and
`json_nullp()` to inspect dynamic values. Legacy `nullp()` remains an alias of
`undefinedp()` and does **not** identify the new null value.

As with other LPC declarations, initialize variables before consuming their
values; a declared type does not change legacy uninitialized-value behavior.
`save_variable`/`restore_variable` and object saves preserve boolean/null values.
Errors are transient: serialize selected `error_info()` fields explicitly.

## Errors

`make_error(code, message, context?, cause?)` constructs a native `error_value`.
`errorp(value)` identifies it. `error_info(value)` returns a detached mapping
with `code`, `message`, `context`, `cause`, and `trace`. Context containers are
copied, cycles are rejected, and object/function handles retain their identity.
The cause is another immutable error or null. Traces exclude arguments and
locals and are captured at construction.

```c
mixed failure;
try {
    file_write("/save/settings.json", json_encode(([ "enabled": true ])));
} catch (failure) {
    mapping info = error_info(failure);
    write(info["code"] + ": " + info["message"] + "\n");
}
```

The catch binding is a previously declared assignable variable; an inline
declaration in `catch (...)` is not supported. `try` selects synchronous catch
or async-aware catch according to the enclosing function, so `await` is legal
inside a try body directly inside an async function.

In modern mode, `catch` and `acatch` return null on success and a native error
on failure, including `throw(0)`. Already structured errors keep their identity,
cause, and original trace. Legacy strings and other thrown values are wrapped
as `runtime.error`; the wrapper trace is the capture boundary, not a recovered
throw-site trace. Scalar thrown values are retained in context; non-scalar
legacy throws record their type rather than copying arbitrary cyclic graphs.
Rethrow with `throw(failure)` to preserve an existing error.

Evaluation-budget exhaustion remains uncatchable. Native error creation does
not make resource exhaustion recoverable.
