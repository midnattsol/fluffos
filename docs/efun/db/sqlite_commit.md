---
title: db / sqlite_commit
---
# sqlite_commit

### NAME

    sqlite_commit() - commit an active SQLite transaction

### SYNOPSIS

    void sqlite_commit(int handle);

### DESCRIPTION

Commits the active transaction. Calling it outside a transaction throws
`db.transaction_state`. A statement failure does not roll back automatically;
repository code must catch the failure and call `sqlite_rollback()`.

### SEE ALSO

`sqlite_begin(3)`, `sqlite_rollback(3)`, `sqlite_execute(3)`
