---
title: general / json_nullp
---
# json_nullp

### SYNOPSIS

    int json_nullp(mixed value);

Identifies the native null value emitted by JSON decoding or the modern `null`
literal. Integer zero and undefined values are not null. The existing `nullp`
efun retains its historical undefined-value behavior.
