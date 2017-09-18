# Format2 - Protostar Challenge

We are given the following binary and its source code:

![image](https://user-images.githubusercontent.com/24576987/30567123-e7cb9c60-9c9c-11e7-9031-fcdf75a7af9b.png)

It looks like the program is almost exactly like the previous challenge, only demanding that the target value is a specific value. Let's try to get back to the previous state we were in:

![image](https://user-images.githubusercontent.com/24576987/30567157-0a0bdbe6-9c9d-11e7-9449-4367ac2844fa.png)

Okay, we have the ```target``` memory location at ```0x080496e4```, but how do we write an actual value to the program? It turns out that ```printf()``` has this very nifty feature to write data, using ```%n```. This will return up to ```n``` bytes, allowing us to exploit ```printf()``` vulnerabilities to write to arbitrary locations. Let's try founding our place on the stack:

![image](https://user-images.githubusercontent.com/24576987/30567480-9657f836-9c9e-11e7-96fc-177336d0631e.png)

... Okay, I guess it was rather close on the stack this time. Luckily, there's not much I have to do to pad the string to get a reliable stack location. The question remains: How do I write 64 bytes to the program? Well it turns out that ```%60x``` will result in 60 bytes that are easily clearable, and coupled with the 4 bytes I have to supply for the input string, it's rather easy:

![image](https://user-images.githubusercontent.com/24576987/30567593-1edfa064-9c9f-11e7-80c8-6f787dedac0a.png)

On to the next task!

