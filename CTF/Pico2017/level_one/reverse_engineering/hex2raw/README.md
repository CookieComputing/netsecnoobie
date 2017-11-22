#Hex2Raw

We are given a binary at the server's location:

![image](https://user-images.githubusercontent.com/24576987/33105281-5fecf5ce-cefa-11e7-9441-69381a7d4b5d.png)

Let's just double check to see if it the same value:
![image](https://user-images.githubusercontent.com/24576987/33105294-6f51456a-cefa-11e7-8253-f142aac7205c.png)

Cool, it looks like the value doesn't change. But what could these values mean? It turns out that these values are hex values (hence the "Hex" part of "Hex2Raw"). Raw could mean a billion things, but in this sense we are interpreted these hex values as raw bytes. But what are these bytes and how can we send them as input?

It turns out that a hex byte is two of these characters (where a single hexadecimal digit stands for 4 bits, and a byte is 8 bits, so 2 hexadecimal characters represent a byte). To print this out, we can use `perl`.

![image](https://user-images.githubusercontent.com/24576987/33105403-e87cf42a-cefa-11e7-8e4b-dedaa12f8f68.png)

And we're done!
