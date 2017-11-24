# Guess the Number

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33191780-a92efdae-d08a-11e7-9652-d977bad4b2d4.png)

Here is the source code:

```c
    /* How well do you know your numbers? */

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>

    void win(void) {
        printf("Congratulations! Have a shell:\n");
        system("/bin/sh -i");
    }

    int main(int argc, char **argv) {
        uintptr_t val;
        char buf[32] = "";

        /* Turn off buffering so we can see output right away */
        setbuf(stdout, NULL);

        printf("Welcome to the number guessing game!\n");
        printf("I'm thinking of a number. Can you guess it?\n");
        printf("Guess right and you get a shell!\n");

        printf("Enter your number: ");
        scanf("%32s", buf);
        val = strtol(buf, NULL, 10);

        printf("You entered %d. Let's see if it was right...\n", val);

        val >>= 4;
        ((void (*)(void))val)();
    }
```

It looks like `val` is essentially the variable we have to overwrite, as it is a function pointer that will lead us to the right place if we manipulate the value just right. But how can we find such a number? Well, the value is being shifted 4 bits to the right, so perhaps a number that is shifted to the left 4 bits will work:

First, let's find the number that the address is located at:

![image](https://user-images.githubusercontent.com/24576987/33191831-3f4079b2-d08b-11e7-9089-5bf019083d0c.png)

The `win` address is located at `0x0804852b`, which means we need to check what decimal value will return the proper address:

![image](https://user-images.githubusercontent.com/24576987/33191844-689736ca-d08b-11e7-8c47-60803340cc7a.png)

Simple enough, right? Let's check the remote server to see if we got it right:

![image](https://user-images.githubusercontent.com/24576987/33191855-8359ac36-d08b-11e7-9697-ec9b99a80276.png)

Huh, it led to an error. Why is this? As explained in the hint, `strtol()` will check for overflows, but interestingly enough it allows for negative numbers. This means we should be able to a negative number that is same as 2152223408 but is interpreted as a negative integer. Let's see what kind of number that is:

![image](https://user-images.githubusercontent.com/24576987/33191887-dfd3b010-d08b-11e7-9997-54c72740a0fe.png)

I went online for a signed binary interpreter and got this number:

![image](https://user-images.githubusercontent.com/24576987/33191892-eebfd644-d08b-11e7-9ca5-1cbf32452d4f.png)

Let's see if it worked:

![image](https://user-images.githubusercontent.com/24576987/33191900-00d9105c-d08c-11e7-8765-1eeb801b1ec7.png)

Success!
