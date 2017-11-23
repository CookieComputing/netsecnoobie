# A Thing Called the Stack

We are asked to solve this challenge:

![image](https://user-images.githubusercontent.com/24576987/33187174-f6a0a808-d05d-11e7-9a18-bf7f2e2195c5.png)

In addition to this challenge, we are given the following code:

```
foo:
    pushl %ebp
    mov %esp, %ebp
    pushl %edi
    pushl %esi
    pushl %ebx
    sub $0xf4, %esp
    movl $0x1, (%esp)
    movl $0x2, 0x4(%esp)
    movl $0x3, 0x8(%esp)
    movl $0x4, 0xc(%esp)
```

I had to re-read the challenge a few times before I got what the challenge was looking for, but the point of the challenge was to calculate the literal byte difference between the original `ebp` (aka the return address) and the esp found at the end of the instruction. One thing to note, however, was that it was not the return address of the next instruction as you would expect in a normal assembly function.

This means that we weren't actually looking for a return address that `eip` would look at, but instead just the original `ebp` value stored in the first assembly instruction. This made the challenge a lot more simpler than I thought it to be.

The stack should look something like this at the end of the procedure:

```
    
        +-------------------+ <-------------- esp points at the top of the stack
        |       %ebx        | - 4 bytes
        +-------------------+
        |       %esi        | - 4 bytes
        +-------------------+
        |       %edi        | - 4 bytes 
        +-------------------+
        |                   |
        |   0xf4 bytes of   | - 0xf4 bytes
        |   random data     |
        |                   |
        +-------------------+
        |       %ebp        | 0x4 bytes
        +-------------------+ <------------- return address here
```

Take note how `mov %esp, %ebp` and the `movl` commands don't actually affect the distance
between the return address and the stack pointer. This is because they don't actually modify the distance between the two values! These `movl` instructions are not affecting the final location of the `esp` and the `return address`, despite changing some values.
