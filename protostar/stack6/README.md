Stack6 - Protostar Challenge

We are given a binary with the following source code:

![image](https://user-images.githubusercontent.com/24576987/30241106-1b207058-954b-11e7-8a2b-f3663b9cd3b2.png)

An interesting thing to note is that ```ret``` is being used to block something. What does ```ret & 0xbf000000``` mean?

It turns out that the ```&``` operand is being used in conjuction with ```0xbf000000``` in order to clear out the stack space. Let's take a look at what could be a stack address and how the ```&``` operand interacts with it:

```
  0xbffffcb0
& 0xbf000000
-------------
  0xbf000000
```

Since ```&``` will result in 0 if both arguments do not have a byte, the resulting value is ```0xbf000000```. This effectively means that anything in the stack space is useless for the program, so we must resort to alternative techniques in order to execute code in this binary.

The page suggests that ret-to-libc is a possible technique, so we will attempt to print "/bin/sh" to see if the technique is valid in this program.

In order for ret2libc to work, we need 2 pieces of data:
.. Some libc function to exploit (We will use ```printf()``` for this writeup)
.. Any arguments necessary for the library function (We will have ```printf()``` call ```/bin/sh```)

We can also find the address of ```exit()``` if we want to exit gracefully, so we will do that.

One of the easiest ways to get ```/bin/bash``` into memory is to place it in as an environment variabe, so this command will work:

```export SHELL="/bin/bash"```

Let's open up the debugger and find the ```printf()``` and ```exit()``` addresses:

![image](https://user-images.githubusercontent.com/24576987/30241211-edaaeaca-954c-11e7-90fa-29a93357a05c.png)

We now have the addresses for the two functions, we still need to find the shell address. That should be simple:

![image](https://user-images.githubusercontent.com/24576987/30241217-1637dae8-954d-11e7-9c63-3ee13887bf57.png)

I used ```x/200xs $esp``` in order to read the first 200 strings below the ESP pointer. Something of interest to note here is that the address ```0xbfffff80``` actually contains the address for "SHELL=/bin/bash", so we need to add 6 bytes to this address to simply get "/bin/bash".

Now that we have all the information necessary, we now need to create the payload

```perl -e 'print "A"x80 . "\x90\xdf\xed\xb7" . "\xc0\x60\xec\xb7" . "\x86\xff\xff\xbf"' > /tmp/shell```

Running this in gdb yields:

![image](https://user-images.githubusercontent.com/24576987/30241294-6d395384-954e-11e7-91e3-195fde92499b.png)
