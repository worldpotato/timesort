# timesort

This is just a fun implementation of a way to sort values based on the time a thread pauses.
I did it just to do something fun with c++ and trying out how to follow the clean code principles.

## Is it good?

No, it doesn't work well with a lot of values.
With my machine it fails when values have a difference of 1 and are more than 37 places apart.
But that should change with the processor speed and maybe with the compiler.

Beside of that it is not working in all cases, it needs a lot of time. No wonder, it works with pausing the threads.

# Argument

The argument is the number of random values which should get sorted.
