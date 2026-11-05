---
title: db / sqlite_query
---
# sqlite_query

### NAME

    sqlite_query() - execute one bounded parameterized SQLite query

### SYNOPSIS

    mixed *sqlite_query(int handle, string sql, mixed *parameters,
                        int max_rows, int max_bytes);

### DESCRIPTION

`sqlite_query()` executes exactly one read-only SQLite statement and returns an
array of row arrays. It steps the prepared statement once and does not retain a
cursor or materialize an unbounded result internally.

`max_rows` bounds the returned rows. `max_bytes` bounds the combined bytes of
text and blob values. Exceeding either bound throws `db.result_limit`; partial
results are never returned. Callers should paginate explicitly in SQL.

SQLite integers, floats, text, blobs, and NULL become LPC `int`, `float`,
`string`, `buffer`, and native `null`, respectively. Result column names are
not included.

Parameter rules are the same as for `sqlite_execute()`.

A statement runs under the caller's evaluation limit: a query that outlives it
is interrupted and the driver raises the usual uncatchable "Too long evaluation"
error. On Linux a shutdown signal also interrupts the statement, so the driver
can stop. Prepared statements are cached per connection and reused for identical
SQL text, so build queries with `?` parameters rather than formatting values in.

### EXAMPLE

```c
mixed *rows = sqlite_query(db,
    "SELECT id, revision FROM instances WHERE id > ? ORDER BY id LIMIT 100",
    ({ after_id }), 100, 65536);
```

### ERRORS

In addition to the SQLite parameter and statement errors, this efun may throw
`db.result_limit` or `db.invalid_text`.

### SEE ALSO

`sqlite_execute(3)`, `db_connect(3)`, `valid_database(4)`
