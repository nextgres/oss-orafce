# Open Source Implementation of DBMS\_PIPE

This package is an emulation of Oracle's package `dbms_pipe`. It provides inter-session comunication. You can send and read any message with or without waiting; list active pipes; set a pipe as private or public; and, use explicit or implicit pipes. 

The maximum number of pipes is 50.

Shared memory is used to send messages.

An example follows:

```
-- Session A
select dbms_pipe.create_pipe('my_pipe',10,true); -- explicit pipe creating
select dbms_pipe.pack_message('neco je jinak');
select dbms_pipe.pack_message('anything is else');
select dbms_pipe.send_message('my_pipe',20,0); -- change limit and send without waiting
select * from dbms_pipe.db_pipes; -- list of current pipes

-- Session B
select dbms_pipe.receive_message('my_pipe',1); -- wait max 1 sec for message
select dbms_pipe.next_item_type(); -- -> 11, text
select dbms_pipe.unpack_message_text();
select dbms_pipe.next_item_type(); -- -> 11, text
select dbms_pipe.unpack_message_text();
select dbms_pipe.next_item_type(); -- -> 0, no more items
select dbms_pipe.remove_pipe('my_pipe');
```

There are some differences compared to Oracle, however:

* limit for pipes isn't in bytes but in elements in pipe
* you can send message without waiting
* you can send empty messages
* `next_item_type` knows about TIMESTAMP (type 13)
* PostgreSQL don't know about the RAW type, use bytea instead

