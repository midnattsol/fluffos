---
title: general / error_info
---
# error_info

### SYNOPSIS

    mapping error_info(mixed failure);

Requires a native error and returns a detached mapping with `code`, `message`,
`context`, `cause`, and `trace`. Changing returned containers does not change
the error. An error cause keeps its immutable identity. A missing cause is the
native null value, not integer zero.
