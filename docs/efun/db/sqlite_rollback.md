---
title: db / sqlite_rollback
---
# sqlite_rollback

### NAME

    sqlite_rollback() - roll back an active SQLite transaction

### SYNOPSIS

    void sqlite_rollback(int handle);

### DESCRIPTION

Rolls back the active transaction. Calling it outside a transaction throws
`db.transaction_state`.

### SEE ALSO

`sqlite_begin(3)`, `sqlite_commit(3)`, `sqlite_execute(3)`
