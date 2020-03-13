# Open Source Implementation of DBMS\_ASSERT

This package protect user input against SQL injection.

* `dbms_assert.enquote_literal(varchar) varchar` - Add leading and trailing quotes, verify that all single quotes are paired with adjacent single quotes.
* `dbms_assert.enquote_name(varchar [, boolean]) varchar` - Enclose name in double quotes. Optional second parameter ensure loweralize of name. Attention - On Oracle is second parameter capitalize!
* `dbms_assert.noop(varchar) varchar` - Returns value without any checking.
* `dbms_assert.qualified_sql_name(varchar) varchar` - This function verifies that the input string is qualified SQL name.
* `dbms_assert.schema_name(varchar) varchar` - Function verifies that input string is an existing schema name.
* `dbms_assert.simple_sql_name(varchar) varchar` - This function verifies that the input string is simple SQL name.
* `dbms_assert.object_name(varchar) varchar` - Verifies that input string is qualified SQL identifier of an existing SQL object.

