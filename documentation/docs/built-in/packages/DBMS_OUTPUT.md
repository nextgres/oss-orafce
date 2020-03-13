# Open Source Implementation of DBMS\_OUTPUT

PostgreSQL sends information to the client via RAISE NOTICE. Oracle uses `dbms_output.put_line()`. This works differently to RAISE NOTICE. Oracle has a session queue where `dbms_output.put_line()` adds a line to the queue and `dbms_output.get_line()` reads from queue. If flag 'serveroutput' is set, then client over all sql statements reads queue. You can use:

```
select dbms_output.enable();
select dbms_output.put_line('first_line');
select dbms_output.put_line('next_line');
select * from dbms_output.get_lines(0);
```

or

```
select dbms_output.enable();
select dbms_output.serveroutput('t');
select dbms_output.put_line('first_line');
```
    
This package contains the following functions:

* `dbms_output.enable()` - ...
* `dbms_output.disable()` - ...
* `dbms_output.serveroutput()` - ...
* `dbms_output.put()` - ...
* `dbms_output.put_line()` - ...
* `dbms_output.new_line()` - ...
* `dbms_output.get_line()` - ...
* `dbms_output.get_lines()` - ...

The package queue is implemented in the session's local memory.

