# Heap0 - Protostar Challenge

We are given the following binary and its source code:

![image](https://user-images.githubusercontent.com/24576987/30664784-de97ef96-9e1c-11e7-8f49-e9b957943f3f.png)

It seems pretty simple: Overflow the ```malloc()``` chunks and break the ```fp()``` pointer to redirect it into ```winner()```. Let's run the program once to see what it does:

![image](https://user-images.githubusercontent.com/24576987/30664841-0f64a510-9e1d-11e7-9554-d46203f47192.png)

Interesting, we are given the ```fp()``` address and the ```data``` address. Subtracting the two values yields 72 bytes, so I need to overwrite 72 bytes of data and then point the function pointer into ```winner()```. Let's whip up a script and try that:

![image](https://user-images.githubusercontent.com/24576987/30664915-47a5b4a0-9e1d-11e7-9ba0-07270273b880.png)

Pretty neat! I've also switched to using ```pwntools``` in preparation for any other challenges I need to automate. The library is incredibly powerful and I hope to have a strong understanding of it before I go into my next CTF.

