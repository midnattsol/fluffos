---
title: mappings / mapping_has
---
# mapping_has

### NAME

    mapping_has() - determine whether a mapping contains a key

### SYNOPSIS

    int mapping_has(mapping values, mixed key);

### DESCRIPTION

Returns `1` if `key` is present and `0` otherwise. The value stored at that
key does not affect the result: zero, an empty string, an empty collection,
and an explicitly stored undefined value all count as present.

The lookup does not insert a missing key or copy the mapping's keys.
Key comparison follows ordinary mapping lookup semantics.

### EXAMPLE

```c
mapping settings = ([ "enabled": 0 ]);
mapping_has(settings, "enabled"); // 1
mapping_has(settings, "missing"); // 0
```

### SEE ALSO

    keys(3), undefinedp(3), map_delete(3)
