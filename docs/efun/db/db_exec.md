---
title: db / db_exec
---
# db_exec

### NAME

    db_exec() - executes an sql statement

### SYNOPSIS

    mixed db_exec( int handle, string sql_query );

### DESCRIPTION

    This function will execute the passed sql statement for the given data‐
    base handle.

    Returns the number of rows in result set on success, or an error string
    otherwise.

:::warning[SQLite legacy API]
For new SQLite code, use `sqlite_execute()` and `sqlite_query()`. The historical
`db_exec()`/`db_fetch()` contract requires a complete row count before fetching;
the SQLite backend therefore executes a result-producing statement once to
count rows and again while fetching them. It also has no parameter binding or
caller-supplied result bounds.
:::

### SEE ALSO

    db_commit(3), db_fetch(3), db_rollback(3), async_db_exec(3),
    sqlite_execute(3), sqlite_query(3),
    valid_database(4)
