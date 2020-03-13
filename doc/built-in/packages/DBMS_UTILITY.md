# Open Source Implementation of DBMS\_UTILITY

* `dms_utility.format_call_stack()` - return a formatted string with content of call stack

```
postgres=# select foo2();
               foo2               
 ---------------------------------
 -----  Call Stack  -----
   line             object
 number  statement  name
      1  return     function foo
      1  return     function foo1
      1  return     function foo2
(1 row)
```

