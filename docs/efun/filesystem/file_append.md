---
title: filesystem / file_append
---
# file_append

### SYNOPSIS

    void file_append(string path, string contents);

### DESCRIPTION

Appends UTF-8 text, creating the file if it does not exist. No newline is added.
Parent directories must already exist. Checks `valid_write` with operation
name `file_append`; rejects directories, symbolic links, NUL bytes, and invalid
UTF-8 input. Returns normally on success and throws on failure.

Unlike `file_write`, append is not an atomic replacement. A failed append may
have written part of its input. It does not guarantee cross-process record
atomicity or durability across power loss.

Failures throw native errors with `io.*` codes and context for path-related
failures. Capture them with modern `try`/`catch` or the legacy `catch` expression.

### SEE ALSO

    file_read(3), file_write(3), write_file(3), valid_write(4)
