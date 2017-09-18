# CVV - CSAW 2017

I had the pleasure of playing with Northeastern's Security lab in this weekend's CSAW 2017 CTF game. While I'm still very inexperienced with actual CTFs (having only done a few high school CTFs before), I enjoyed the challenge and the process of learning to play CTFs, although it was admittedly frustrating at times.

The program was hosted at ``misc.chal.csaw.io`` on port ```8308```. Upon entering the challenge, I was then asked for a type of credit card:

![image](https://user-images.githubusercontent.com/24576987/30565838-c609b62a-9c97-11e7-8876-045bc17a1be6.png)

The program also provided a different input every time it was launched, hence this new picture:

![image](https://user-images.githubusercontent.com/24576987/30565938-1a0376b2-9c98-11e7-9b47-d0ea8df4ef5b.png)

After some research, I came across the [Luhn's algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm), which banks use in order to verify whether or not a credit card is valid. Upon further research, I also found a [very useful tool](https://github.com/eye9poob/python/blob/master/credit-card-numbers-generator.py) which I then used to craft fake credit card numbers that were accepted by the program.

I did not anticipate the sheer amount of requirements that the challenge had provided, and thus my code was not optimized for refactoring, which caused it to be the ugly conglomerate it is now :).

![image](https://user-images.githubusercontent.com/24576987/30566137-c89ec546-9c98-11e7-82e1-4f7ef7ffa351.png)


![image](https://user-images.githubusercontent.com/24576987/30566154-d6b116f2-9c98-11e7-8e13-8ddd060fa8c1.png)


![image](https://user-images.githubusercontent.com/24576987/30566162-dfb19164-9c98-11e7-9ee5-77728b0f1761.png)

![image](https://user-images.githubusercontent.com/24576987/30566177-ee61d41c-9c98-11e7-842f-e5966a9cfd54.png)

At this point, my socket kept returning errors, so I had to manually enter the verification of these credit cards. Luckily, this was the last criteria necessary to get the flag, so I lucked out in having to do any refactoring.
