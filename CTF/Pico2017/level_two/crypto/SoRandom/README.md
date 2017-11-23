# SoRandom

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33187954-baedd51e-d063-11e7-9823-936d9c5d9884.png)

Along with that challenge, we are given the following code:

![image](https://user-images.githubusercontent.com/24576987/33187974-d8c2acae-d063-11e7-8272-da85c721b552.png)

Upon connecting to the shell server, we are given this flag:

![image](https://user-images.githubusercontent.com/24576987/33187986-f5b2713c-d063-11e7-9b72-d6df8dbb4718.png)

Well that's all fine and dandy, but how can we crack the code and grab the flag if it's impossible to get certainty from randomness? Well, quite simply: you can't. It is theoretically impossible to get something replicable absolutely from true randomness, but computers don't work with true randomness.

Computers compute pseudo-randomness, which is essentially taking computations from a "random-enough" state and then working off of that program. This deterministic way of calculating something somewhat random suggests that it is random enough to be useful for most applications, but the `random()` used in Python dictates the initial `seed` value, which is explicitly given to us.

Wait a second, if `seed()` is given to us, then doesn't that mean we can reliable predict what will happen? Let's go into the python interpreter and check this out for ourselves:

![image](https://user-images.githubusercontent.com/24576987/33188052-958fbaca-d064-11e7-9ec4-355b1a6b85d3.png)

Aha! That means it is possible for us defeat the "random" in the crypto file. So let's see how we could defeat the code...

One interesting observation in this program is how the values of each character are based off of the `ord()` values of the lower and upper case values. The difference between each character is

`Given character - base character + some random int`
All of this is modulo 26, which suggests that the values are being encrypted with these random seeds.

But what if we tried to decrypt the characters? What would that look like? It would look something similar to this:

`Encrypted character - base character - the same random int`
The way this works is that the random integer is subtracted from the difference, and since modulo 26 allows us to wrap around, this allows the encryption program to become a decryption program. Let's see it in action:

![image](https://user-images.githubusercontent.com/24576987/33188167-84fa3338-d065-11e7-8fe8-a1026b9ba63d.png)

And there's the flag! Remember not to leave the seed somewhere insecure next time :)
