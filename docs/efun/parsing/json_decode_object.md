---
title: parsing / json_decode_object
---
# json_decode_object

### SYNOPSIS

    mapping json_decode_object(string | buffer source);

Like `json_decode`, but requires a JSON object at the root. Arrays and scalar
roots raise a native error rather than returning a different LPC type.
