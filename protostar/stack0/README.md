# Stack 0 for Protostar

This is my writeup for Exploit-Exercises' Protostar VM. I am going to work on the Protostar challenge as a refresher on many CTF binary exploitation challenges. Let's get started:

----

We are given a binary aptly named "stack0" with the following source code:

![image](https://user-images.githubusercontent.com/24576987/30235100-6074d302-94d2-11e7-9888-c2a50eb89710.png)

The C function ```gets()``` is a well-known vulnerable function, allowing us to overwrite much more data than any developer would typically expect. Thus, we can abuse the code to achieve our objective.

The function merely checks to see if we have changed the modified value. Knowing that the buffer is only 64 bytes, we can easily create something to overflow into the modified value.

Let's debug the program just to confirm our suspicions:

![image](https://user-images.githubusercontent.com/24576987/30235158-27376b44-94d3-11e7-9a97-0bbc89dba214.png)

it seems that the program has placed the modified variable at ```esp+0x5c``` and the buffer at ```esp+0x1c```. The difference between those two distances is exactly 64 bytes, so any more would cause the ```modified``` variable to be overflowed. Let's do it.

```perl -e 'print "A"x65' | ./stack0```

Using this command, we have successfully overflowed the stack.
![image](https://user-images.githubusercontent.com/24576987/30235203-bd7087da-94d3-11e7-8f5c-033db6a0d4ea.png)
