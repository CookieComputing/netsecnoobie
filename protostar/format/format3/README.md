# Format3 - Protostar Challenge

We are given the following binary and its source code:

![image](https://user-images.githubusercontent.com/24576987/30568829-53ca9116-9ca5-11e7-9a42-9fa02802d6e8.png)

The program expects target to be a specific value, similar to what we did previously but with a little trick added to it. Let's first get a target value:

![image](https://user-images.githubusercontent.com/24576987/30568847-7a5ebc1c-9ca5-11e7-84e1-83375c8c2f1a.png)

Alright, now the next step is to figure out where on the stack are we:

![image](https://user-images.githubusercontent.com/24576987/30568861-91e5f530-9ca5-11e7-99d3-70bdaec6d7dc.png)

The neat thing about this challenge is that it recommends its participants to use ```$hn``` instead of the classic ```$n``` trick. In its essence, ```$hn``` only writes to two bytes instead of the four bytes we all know and love in x86 architecture. This leaves us plenty of space to write to both halfs of the memory address. To do that, however, requires that we have another space on the stack in order to direct our memory writes to. Let's just quickly check that we can do this:

![image](https://user-images.githubusercontent.com/24576987/30568943-02a9640a-9ca6-11e7-95b9-3c550eb1ae67.png)

Awesome, it worked! The next step is to figure out how to write the right amount of data to the memory addresses.

It turns out that its pretty tough to reverse the amount of bytes in a memory address, but it is possible to instead "wrap around" the amount of bytes written to something and put it into the proper place. This can be done by simply writing to a greater amount, while discarding the most significant bit. If you had already written 4618 bytes and wanted to then write 1024 bits, you would convert the number into this:

```0x4618 -> 0x11024```

This in turn allows us to write the two bytes as we desired. Let's try it:

![image](https://user-images.githubusercontent.com/24576987/30569082-b5132fc2-9ca6-11e7-85fc-b880cbbc8e51.png)

And there we go! Challenge solved.
