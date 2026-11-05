---
title: filesystem / file_write
---
# file_write

### SYNOPSIS

    void file_write(string path, string contents);

### DESCRIPTION

Creates or replaces a complete UTF-8 text file. Unlike `write_file`, this
operation never appends. It returns normally on success and throws on failure.
An empty string creates an empty file. No newline is added. NUL bytes, invalid
UTF-8, directories, and symbolic-link destinations are rejected.

The driver checks `valid_write` using the operation name `file_write`. It creates
an exclusive temporary file alongside the approved destination, writes and
closes it, then renames it over the destination. Temporary files
are removed on failure. Parent directories must already exist. On POSIX, a
replacement keeps the mode of the file it replaces and a new file gets the same
umask-derived mode `write_file` would give it; ownership and hard-link
relationships are not preserved.

Readers see the previous or new file, not partially published content. This is
not a transaction across multiple files and does not promise durability across
power loss. Concurrent writers use last-successful-replacement semantics.

Failures throw native errors with `io.*` codes and context for path-related
failures. Capture them with modern `try`/`catch` or the legacy `catch` expression.

### SEE ALSO

    file_read(3), file_append(3), write_file(3), valid_write(4)
