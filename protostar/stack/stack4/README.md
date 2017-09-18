# Stack4 - Protostar Challenge

This is Protostar's Stack4 challenge. The program provides the following source code:

![image](https://user-images.githubusercontent.com/24576987/30235718-ca6376b8-94d9-11e7-9a0b-d60c7be1c65b.png)

In this source code, there are no variables or function pointers to overflow, so what is there to abuse?

It turns out that with a bit of a better understanding of the stack, we can understand what is goingon.

Intel x86 architecture handles function in an interesting way. The [University of Maryland's page](https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Mips/stack.html) describes the process very thoroughly, so I would recommend looking at that page before continuing.

The objective is to overwrite the saved return address of the program so that when the function concludes, the eip restored will be the corrupted address instead of the true function. I've already ran the program in a debugger with a few A's just to see how far the program goes, but let's see the results: 

![image](https://user-images.githubusercontent.com/24576987/30235785-ecd3c30a-94da-11e7-8ca1-f373dfb58c6b.png)

As you can see, the saved eip is at ```0xbffffcbc``` and holds ```0xb7eadc76```. The start of the buffer lies at ```0xbffffc70```. Subtracting the two addresses yields 76 bytes, thus we need to write junk in 76 bytes and then rewrite the return address with the win function.

![image](https://user-images.githubusercontent.com/24576987/30235808-79d69494-94db-11e7-98c9-1b08b1d9ad24.png)

