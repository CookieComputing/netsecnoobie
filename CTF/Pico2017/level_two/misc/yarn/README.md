# Yarn

We are given the following Challenge:

![image](https://user-images.githubusercontent.com/24576987/33189228-d7e0ed72-d06e-11e7-94d1-892cde2161a3.png)

Okay, so the challenge asks us to run `strings` on the yarn executable. Let's do that:

![image](https://user-images.githubusercontent.com/24576987/33189247-f4aeaa7a-d06e-11e7-89d2-bc3968342007.png)

I'm getting a lot of text, but for some reason the flag isn't there. What could the problem be?

Let's try looking at the `man` page for `strings`

![image](https://user-images.githubusercontent.com/24576987/33189262-14481088-d06f-11e7-9754-396966f79989.png)

Aha! Let's try that:

![image](https://user-images.githubusercontent.com/24576987/33189278-3451ab28-d06f-11e7-9b9c-c52d89488683.png)

Spotted you! Another 55 points for me!
