---
title: parsing / json_encode
---
# json_encode

### SYNOPSIS

    string json_encode(mixed value);

Encodes JSON-compatible LPC data. Mapping keys must be strings. Native booleans
and null retain their JSON identity; integer 0 is encoded as `0`. Rejects
undefined values, classes, objects, functions, promises, native errors,
non-finite numbers, reference cycles, oversized output and nesting beyond 64
levels. Shared acyclic substructures are allowed. Errors use `json.encode`.

The result is compact JSON with deterministic object-key ordering. No files are
written. Use `file_write(path, json_encode(value))` for atomic file replacement.
