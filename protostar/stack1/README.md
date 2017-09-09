# Stack1 - Protostar Challenge

This is the second challenge of Exploit Exercises' Protostar VM. Let's get started:

We are given the binary "stack1" and the following source code:

![image](https://user-images.githubusercontent.com/24576987/30235238-4f3506fa-94d4-11e7-82aa-bb14d76d071e.png)

The challenge is very similar to stack0, except this time it asks for a specific value. Let's go into the debugger just to check if anything has changed:

![image](https://user-images.githubusercontent.com/24576987/30235255-8b0675e2-94d4-11e7-9ab4-19c4039d5b2d.png)

Well, it appears that the program is simply checking for this value to be placed. Remember that x86 applies little endian ordering to its bytes, so our payload must have the hex values in reverse. Also remember that the program demands an argument, so we must put our payload in a shell command.

```./stack1 $(perl -e 'print "A"x64 . "\x64\x63\x62\x61"')```

Running this command will give us the solution:

![image](https://user-images.githubusercontent.com/24576987/30235292-2caef41e-94d5-11e7-9ebe-bc1eb2d67fd4.png)


