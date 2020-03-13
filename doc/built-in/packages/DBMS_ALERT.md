# Open Source Implementation of DBMS\_ALERT

Another means of inter-process communication.

```
-- Session A
select dbms_alert.register('boo');
select * from dbms_alert.waitany(10);

-- Session B
select dbms_alert.register('boo');
select * from dbms_alert.waitany(10);

-- Session C
select dbms_alert.signal('boo','Nice day');
```

