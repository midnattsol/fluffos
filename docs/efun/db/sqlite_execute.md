---
title: db / sqlite_execute
---
# sqlite_execute

### NAME

    sqlite_execute() - execute one parameterized SQLite write statement

### SYNOPSIS

    int sqlite_execute(int handle, string sql, mixed *parameters);

### DESCRIPTION

`sqlite_execute()` prepares and executes exactly one SQLite statement. Use an
anonymous `?` placeholder for every parameter. Named and numbered placeholders
are rejected.

The statement must be a write statement with no result columns. Use
`sqlite_query()` for read-only statements. The return value is SQLite's changed
row count for the statement.

Supported parameters are `int`, `float`, `string`, `buffer`, `bool`, `null`,
and legacy undefined zero. Strings must be valid UTF-8 without embedded NUL
bytes; use a buffer for binary data.

### ERRORS

Failures throw native errors. Stable codes include `db.invalid_handle`,
`db.unsupported_backend`, `db.invalid_statement`, `db.invalid_parameter`,
`db.invalid_text`, and `db.sqlite`. Error context never contains SQL text or
bound parameter values.

### EXAMPLE

```c
int changed = sqlite_execute(db,
    "UPDATE instances SET revision = revision + 1 WHERE id = ? AND revision = ?",
    ({ instance_id, expected_revision }));
```

### SEE ALSO

`sqlite_query(3)`, `sqlite_begin(3)`, `sqlite_commit(3)`, `sqlite_rollback(3)`,
`db_connect(3)`, `valid_database(4)`
