# Orangev3 - CSAW 2017 Challenge

We are given the following prompt:

![image](https://user-images.githubusercontent.com/24576987/30566464-3070bb7e-9c9a-11e7-9a62-36056257d038.png)

It seems pretty similar to the Orangev1 challenge, so let's dig into the challenge:

![image](https://user-images.githubusercontent.com/24576987/30566512-58c02fec-9c9a-11e7-9596-a0ce7bf5b318.png)

It looks exactly like orangev1, but I have a hunch that something is different this time around:

![image](https://user-images.githubusercontent.com/24576987/30566543-764682a0-9c9a-11e7-9008-c983c4aed884.png)

Hmm, they have seemed to block double encoding. This challenge was incredibly tough, and I tried a bunch of things before the competition ended. Naturally, I wasn't able to succeed in pwning the challenge before time ran out, but I did discover a few things about the challenge before I looked at a writeup:

I noticed that .txt files were still regarded as "valid", thus I could read .txt if I was to find the solution to the challenge:

![image](https://user-images.githubusercontent.com/24576987/30566611-bd5accf0-9c9a-11e7-9549-8801341485df.png)

Next up, I also discovered that the program processed question marks and allowed me to access the directory listing of the web page:

![image](https://user-images.githubusercontent.com/24576987/30566650-de3f1d86-9c9a-11e7-801b-1d08cd014bf5.png)

This was about as far as I got before I was just stuck in a rut for the rest of the competition, however, I tried to think about other means of bypassing the encoding filter. Seeing as there was no other way to get into the parent directory, I looked into ways to try and encode the ```..``` command using different encoding schemes, and it turns out that [I got very, very close](https://en.wikipedia.org/wiki/Percent-encoding#Non-standard_implementations) to the actual solution, but still no cigar.

Having admitted defeat, I looked at this [nifty writeup](https://aadityapurani.com/2017/09/17/csaw-ctf-2017-writeups/), which suggested that there existed a UTF-16 character which functioned as the solution to the problem, and [it turns out there was!](http://www.fileformat.info/info/unicode/char/012e/index.htm)

![image](https://user-images.githubusercontent.com/24576987/30566880-d99bad52-9c9b-11e7-835f-2494d701bc81.png)

This was definitely a learning process, as I had in fact checked the website for the full stop UTF-16 encoding, but did not consider this character as a possibility. There's always next time!
