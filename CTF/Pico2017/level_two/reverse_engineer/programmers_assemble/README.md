# Programmers Assemble

We are given the following challenge: 
![image](https://user-images.githubusercontent.com/24576987/33187523-4faf0596-d060-11e7-8595-1aaa1ade7c5c.png)

We are also given the following code:

```
.global main

main:
    mov $XXXXXXX, %eax
    mov $0, %ebx
    mov $0x6, %ecx
loop:
    test %eax, %eax
    jz fin
    add %ecx, %ebx
    dec %eax
    jmp loop
fin:
    cmp $0x55bc, %ebx
    je good
    mov $0, %eax
    jmp end
good:
    mov $1, %eax
end:
    ret
```

The goal is to find a `eax` value such that the program will return one. But what does all of this mean? Let's break it down

## Assembly Breakdown

In x86, there are two types of disassembly languages that most people will use: These are Intel and AT&T notation. You can easily identify AT&T notation by looking for `$` and `%` signs around, as those things are often the most spottable difference between the two syntaxes.

The operands go in the following:
`mov source, destination`

This is different from what Intel goes by, as the Intel syntax will do something along the lines of `mov destination, source`

Now that we have learned the way parameters are organized, let's see what all these instructions mean.

`mov` means to copy the contents from one place to another. Yes, it is a copy and not a cut/paste, so the values will still be in the source location.

`test` will subtract the `destination` value from the `source` value and set up some flags if anything happens.

`jz` will jump to the specified address (in this case, we will just jump to `fin`) if the zero flag has been checked

`add` will add the destination to the source.

`dec` will subtract one from the destination.

`jmp` will just jump to the specified location.

So the function looks like it is looping, hence the function name `loop`. But how does the loop terminate? Looking at the `test` instruction, the loop terminates when `eax` is zero, which is the value we are trying to determine. How is everything else handled?

`fin` will return `1` if and only if `ebx` yields `0x55bc`. How can `ebx` become that value? Let's look at loop again and see what it does for us:

```
loop:
    test %eax, %eax
    jz fin
    add %ecx, %ebx
    dec %eax
    jmp loop
```

So it looks like loop will add `ecx` to `ebx` every time and then call loop again, this time with `eax` decremented. This means that the function is essentially doing something like this:

```
for (int i = x; i < 0; i--) {
    ebx += ecx;
}
```

Some simple math will help us find the answer then. If `ecx` is `0x6`, and `ebx` has to be `0x55bc`, then `0x55bc / 0x6 = 0xe4a`

And we're done.

