# Format1 - Protostar Challenge

We are given the following binary and its source code:

![image](https://user-images.githubusercontent.com/24576987/30565430-3a61bede-9c96-11e7-8f13-900c8765a995.png)

The program itself is a classic printf vulnerability, however the challenge notes that "objdump -t" is recommended, and that the input string is placed high up (or I suppose very below) the stack.

Lets do as they say and check out the dump of the binary:

![image](https://user-images.githubusercontent.com/24576987/30565507-8c7e28e2-9c96-11e7-9d01-b6df1f6d8f39.png)

The source code suggests that if the value of the ```target``` variable is changed to anything other than 0, then the program is successfully compromised. Fair enough, let's keep note of it's memory address while we probe for the actual stack location.

The challenge noted that the input string was placed very high up, so let's see what happens when we check 150 pointers on the stack:

![image](https://user-images.githubusercontent.com/24576987/30565589-de5dbd4e-9c96-11e7-9f2d-c8c26d9a621b.png)

As it turns out, I found the location after a good estimate. I had to do some padding in order to confirm the exact location of my exploit, but I eventually found it at the 130th position.

Changing my code a bit, I was able to successfully compromise the program:

![image](https://user-images.githubusercontent.com/24576987/30565630-13be2e60-9c97-11e7-81ee-76fd265fcca8.png)

