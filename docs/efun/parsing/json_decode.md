---
title: parsing / json_decode
---
# json_decode

### SYNOPSIS

    mixed json_decode(string | buffer source);

Parses UTF-8 JSON into LPC mappings, arrays, strings, integers, floats, native
booleans and native null. It does not read files. Duplicate object keys, embedded
NUL in strings, out-of-range integers and nesting beyond 64 levels are rejected.
Input size and collection/string sizes obey driver limits. Floating-point
numbers use LPC floating-point precision.

Throws a native error. Syntax errors use code `json.syntax` and include the
parser's 1-based byte offset in context; messages include parser diagnostics.
Other conversion errors use `json.invalid_data`. Use `json_decode_object` to
require an object at the root.
