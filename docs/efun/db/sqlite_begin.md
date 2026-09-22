---
title: db / sqlite_begin
---
# sqlite_begin

### NAME

    sqlite_begin() - begin an immediate SQLite transaction

### SYNOPSIS

    void sqlite_begin(int handle);

### DESCRIPTION

Begins a transaction using `BEGIN IMMEDIATE`. Nested transactions are rejected.
The call also fails while legacy asynchronous work is pending for the same
connection.

Keep the complete transaction synchronous. Do not await, schedule continuation
work, or call `async_db_exec()` before committing or rolling back.

### ERRORS

Wrong transaction state throws `db.transaction_state`; an async conflict throws
`db.async_conflict`; SQLite failures throw `db.sqlite`.

### SEE ALSO

`sqlite_execute(3)`, `sqlite_query(3)`, `sqlite_commit(3)`, `sqlite_rollback(3)`
