# hashtable_ansi_c
The default C library doesn't provide a hashtable (a.k.a dictionary). However, we can certainly make a hashtable from scratch! This is a simple attempt to do it.

To compile and run this project, just clone the repository and run the command `./configure`. Gcc is a mandatory dependency and Valgrind is an optional one.
The status of the current compiling of the project can be seen in the `Actions` button, here on this Github page.

Also, in order to change the Hashtable's array size for testing purposes: just change the macro `ARRAYMAX` to the desired size (the default is 50).

To compile and run in your linux machine, just clone the repository to your local folder and:
`$ cd hashtable_ansi_c`
`$ ./configure`
and then
`$ make check`

The last command will perform asserts of the hashtable's functionality while also performing memory checks with valgrind.
