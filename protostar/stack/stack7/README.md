# Stack7 - Protostar Challenge

We are given the following binary with its source code:

![image](https://user-images.githubusercontent.com/24576987/30410451-23ad1f28-98d9-11e7-93dd-1df6b6628773.png)

The challenge in contrast to Stack 6 is that they remove the ret2libc technique by checking the return address for 0xb.., where libc is located.

The key, however, is that return-oriented programming still works in this exploit.

While ```strdup()``` may be one way to exploit this program, I decided instead to use the return address stored at that location to use ROP.

First I had to find a ret gadget to bypass the restriction in place:

![image](https://user-images.githubusercontent.com/24576987/30410724-e111d4fe-98da-11e7-9563-ec568872f632.png)

I decided to use ```0x08048383``` as my return gadget.

Afterwards, I found the addresses for ```printf()```, ```exit()```, as well as my own environmental variable ```HI``` which was set to ```"/bin/sh"```.

![image](https://user-images.githubusercontent.com/24576987/30410761-18c4a566-98db-11e7-8736-91db95bbc88c.png)

I then crafted the exploit to look like this:

```[buffer filler] [printf() address] [exit() address] [pointer to HI]```

Running the program in gdb, I got this:

![image](https://user-images.githubusercontent.com/24576987/30410808-44bbd6e4-98db-11e7-806f-83fa59484751.png)

