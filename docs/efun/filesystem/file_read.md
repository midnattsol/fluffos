---
title: filesystem / file_read
---
# file_read

### SYNOPSIS

    string file_read(string path);

### DESCRIPTION

Reads an entire UTF-8 text file after consulting `valid_read` with operation
name `file_read`. An empty file returns an empty string. Missing or inaccessible
files throw rather than returning zero. Directories, symbolic links, embedded
NUL bytes, and invalid UTF-8 are rejected. Line endings are preserved.

The result is bounded by both `maximum read file size` and `maximum string
length`. Exceeding either limit throws rather than returning truncated data.

Failures throw native errors with `io.*` codes. Missing files use `io.not_found`;
the requested path is included in context for path-related failures.

### SEE ALSO

    file_write(3), file_append(3), read_file(3), valid_read(4)
