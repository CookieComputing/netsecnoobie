# Captcha Exploits



![image](https://user-images.githubusercontent.com/24576987/29299973-68f8e25c-8140-11e7-9e1f-b6a93d890b54.png)

I was bored today and I wanted to do something interesting, so I decided to attack my friend's website (with his permission, of course).



![image](https://user-images.githubusercontent.com/24576987/29300024-cd7c76c6-8140-11e7-9e94-97253697ea54.png)

It turns out that he forgot to add a captcha to his website, so as a practical joke, I decided to whip up something to tell him to work on that captcha ;)

![image](https://user-images.githubusercontent.com/24576987/29300167-d9618552-8141-11e7-8051-3e11f386a85a.png)

Using Burp, I was able to find the parameters sent in the POST request, and I crafted my exploit to replicate a user.

The goal was to create a program that would flood his database with a bunch of useless accounts, just to remind him to fix up his website. After creating a proof of concept via test.py, I then crafted a quick exploit that would send a bunch of payloads to his website and create a bunch of unnecessary accounts.

The exploit file could be optimized infinitely, but I wanted to get it out as soon as possible to just let him know.
