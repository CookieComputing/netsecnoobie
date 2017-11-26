# Biscuit

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33241225-8d603a18-d290-11e7-93f2-e4824c98e3bc.png)

Let's go into the web site and see what's happening:

![image](https://user-images.githubusercontent.com/24576987/33241229-9f3fb63c-d290-11e7-9907-5d75ee338183.png)

Hmm, so there seems to be no particular text field or anything we can misuse. Let's try looking into the source code for anything interesting:

```html
    <html>

    <!-- Storing stuff in the same directory as your web server doesn't seem like a good idea -->
    <!-- Thankfully, we use a hidden one that is super PRIVATE, to protect our cookies.sqlite file -->
    <style>
    body{
        background-image: url("private/image.png");
    }
    </style>


    <body >

    <div style='background:white;margin: auto;border: 1px solid red;width: 600px; margin-top: 20%;' >
    <center>
    <form style="font-size: 40px; ">
    Access Denied</form>
    </center>
    </div>



    </body>

    </html>
```

There are a couple of things that stick out in this code:

```html
    <!-- Storing stuff in the same directory as your web server doesn't seem like a good idea -->
    <!-- Thankfully, we use a hidden one that is super PRIVATE, to protect our cookies.sqlite file -->
```

```css
    body{
        background-image: url("private/image.png");
    }
```

Now, why do these stick out? Well, the comments suggest that there is a secret file probably called `cookies.sqlite` somewhere in a private directory: emphasis on the `private`. Now, this css body gives us a clue on what it may actually be called, which is `private`.

So we have an idea: there may be a file called `cookies.sqlite` in the `private` directory, but how do we access this file?

If you've ever looked into HTML before (as many beginners start of with), you'll realize that there is an element called `<a>` with an attribute called `href`. This allows us to *link* a particular resource to files on the web, for example:

`<a href="google.com"> Click me to go to google! </a>`

However, did you also know that it can be used to *relatively* find files on the web server itself? Let's see if we can abuse this to access the secret file:

![image](https://user-images.githubusercontent.com/24576987/33241333-d889f4d8-d291-11e7-8e73-3fef9af8a135.png)

Aha! So we actually can download files using this neat trick! Let's try to see if we can view this file to see if there is any we can grab:

![image](https://user-images.githubusercontent.com/24576987/33241354-10c72c8a-d292-11e7-803b-09f4ce77bd74.png)

This requires a little bit of knowledge with how to select SQL tables, but it's relatively straightforward to access from my example. Hmm, interesting! So it looks like there are a few fields that we can look at, but what do these fields stand for?

We can figure out what these column fields represent by turning on the headers:

`.headers ON`

![image](https://user-images.githubusercontent.com/24576987/33241372-50f1e962-d292-11e7-962b-4ee48ac80707.png)

Okay, well what can we do with this? Well, looking at the actual filename, `cookies.sqlite` implies that this stores the user's cookies for the website. This holds some serious weight: Cookies are how web servers manage user sessions. If an attacker were to control a user's cookies, they can impersonate a user and then essentially act as the user from then on. 

With this setup, we can possibly impersonate some user. But how do we change our cookies to theirs? Well, let's get back to the website and edit it using a nifty chrome extension I found online:

![image](https://user-images.githubusercontent.com/24576987/33241398-a4fdd070-d292-11e7-81bf-7c355cdaa9c1.png)

And there we go! We've got the flag!
