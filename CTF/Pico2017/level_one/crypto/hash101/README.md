# Hash101 Challenge

We are given an address, `shell2017.picoctf.com:51461`, and we need to connect to it to solve the challenge

Let's do that:

![image](https://user-images.githubusercontent.com/24576987/32702747-493af8c8-c7b9-11e7-8797-92c76e3691c9.png)

Although we could try and use the table they suggest, there are already tools online to find it:

![image](https://user-images.githubusercontent.com/24576987/32702749-537f1fbc-c7b9-11e7-9e16-f32523a3ea5e.png)

It looks the text should be `pwning`. Let's try it!

![image](https://user-images.githubusercontent.com/24576987/32702752-638fe35a-c7b9-11e7-92cd-12697c6b7a75.png)

This looks simple enough. Let's go back to the website and pull the hex values from there:

![image](https://user-images.githubusercontent.com/24576987/32702761-7ab2d204-c7b9-11e7-9c7a-ccb6b8d1a66f.png)

Okay, now we have to convert the hexadecimal into decimal. Luckily python does that in two seconds:

![image](https://user-images.githubusercontent.com/24576987/32702764-863c9150-c7b9-11e7-99f7-082bd3797d35.png)

Let's put that into the program:

![image](https://user-images.githubusercontent.com/24576987/32702768-926a5c82-c7b9-11e7-900d-4efbaee70c9e.png)


The next challenge needs us to convert the character values from ascii into their respective decimal values, and then have this integer modulo 16.

Ideally, the solution will be something like this:

`16 % 16 = 0`

But what is the value for `16`? Well, we can always jump to python and use its `chr()` function:

![image](https://user-images.githubusercontent.com/24576987/32702779-c0988804-c7b9-11e7-87ec-19f4f1cd856d.png)


But how do we represent `\x10` using keystrokes? Well, you could always injecct it using something like `perl` or Python's command line interpreter using something like `python -C 'print "\x10"'`, but let's try getting something that can be solved using our keystrokes.

Perhaps we can find another combination of letters that will return the right value?

![image](https://user-images.githubusercontent.com/24576987/32702770-acc4d45e-c7b9-11e7-8bdf-eb2b9d2df442.png)


Aha! Using some knowledge of modulo, we can remove all multiples of 16 and just get something with a remainder of 0. One of these combinations happen to be the string `P`. Let's try it:

![image](https://user-images.githubusercontent.com/24576987/32702794-e434842a-c7b9-11e7-9acb-b02388d03f6b.png)

Well, we obviously can't calculate every single hash that has been made, so let's just plug it into google and see what comes up:

![image](https://user-images.githubusercontent.com/24576987/32702803-fbcf91b0-c7b9-11e7-90fa-be04c38f9f4a.png)

I found it on this website and that supposedly has the answer there. Let's see if entering it will return the right value:

![image](https://user-images.githubusercontent.com/24576987/32702807-109cb956-c7ba-11e7-937d-56a625b0548d.png)

And we're done!

