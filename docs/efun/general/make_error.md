---
title: general / make_error
---
# make_error

### SYNOPSIS

    error_value make_error(string code, string message, mapping context, mixed cause);

`context` and `cause` are optional. Code must be nonempty. Cause must be a native
error or an absent value. The returned error is a first-class immutable value;
throwing is explicit with `throw(value)`.

Context containers are snapshotted to a maximum depth of 64. Cycles and mutable
container keys are rejected. Object/function handles are retained as handles.
The construction-site trace includes source locations but no arguments/locals.

See [modern values and errors](../../lpc/types/modern).
