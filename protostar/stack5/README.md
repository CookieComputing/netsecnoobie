# Stack5 - Protostar Challenge

This is Protostar's stack 5 challenge. This one was a particular pain, simply because of the fact that it irritated me so much when I tried to find the reason as to why my payload was not working.

We are given the following binary and its source code:

![image](https://user-images.githubusercontent.com/24576987/30236751-11bf1c6e-94ef-11e7-91fa-db0aaa4a53ba.png)

The objective is to force EIP to point to our own shellcode and then have it execute it. Simple enough:

![image](https://user-images.githubusercontent.com/24576987/30236756-4783451e-94ef-11e7-87f1-d6e15c79d7bf.png)

Huh? Why is it crashing? I've been bashing my head against this for a while.
I ended up checking the debugger to see if it was actually being run:

![image](https://user-images.githubusercontent.com/24576987/30236761-7213b372-94ef-11e7-892c-0d05bc0a76e4.png)

So the program did in fact run, but I'm still not quite sure why it kept returning ```Segmentation Fault```. My guess is that the binary may be NX-configured, but that may be far-fetched. Others have done very similar solutions to my own, so I will consider this a completed one, despite this odd ```Segmentation Fault``` issue.
