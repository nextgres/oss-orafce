# Open Source Implementation of DBMS\_RANDOM

* `dbms_random.initialize(int)` - Initialize package with a seed value.
* `dbms_random.normal()` - Returns random numbers in a standard normal distribution.
* `dbms_random.random()` - Returns random number from -2^31 .. 2^31.
* `dbms_random.seed(int)` - ...
* `dbms_random.seed(text)` - Reset seed value.
* `dbms_random.string(opt text(1), len int)` - Create random string
* `dbms_random.terminate()` - Terminate package (do nothing in Pg)
* `dbms_random.value()` - Returns a random number from [0.0 - 1.0) 
* `dbms_random.value(low double precision, high double precision)` - Returns a random number from [low, high)

