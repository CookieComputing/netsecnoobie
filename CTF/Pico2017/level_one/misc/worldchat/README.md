# WorldChat

We are asked to connect to the server and find the flag:

![image](https://user-images.githubusercontent.com/24576987/32645488-7eb21d66-c5b5-11e7-8788-a100dacd8e99.png)

The program goes on for quite a while, and it would be impractical to find it by hand. Perhaps we can filter the results to find only the strings that say flag?

`nc shell2017.picoctf.com | grep flag`

![image](https://user-images.githubusercontent.com/24576987/32645536-b8a67f44-c5b5-11e7-8311-5904ee36ff58.png)

Eventually we will be able to find the rest of the flag by looking through the results.

ab4b181f3bc927589e0d79a4845a3ace
