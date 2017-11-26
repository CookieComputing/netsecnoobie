# Meta Find Me

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33193558-88ff7704-d097-11e7-8f41-2b572bf4c524.png)

Here is the image:

![image](https://user-images.githubusercontent.com/24576987/33193580-b535aa96-d097-11e7-810a-a2957e17ccd5.png)

Well, there's nothing we can do about the data in the photo, but perhaps there is something we can do with the metadata of the photo? Every image has some metadata related to a file, but we don't necessarily see it too often. This is very useful for forensics, however, as it tells alot of information about the image, such as where it was taken and the time.

Let's try using `exiftool` to see what information we can find:

![image](https://user-images.githubusercontent.com/24576987/33193607-e7d7e6bc-d097-11e7-927a-3585163001bb.png)

Huh, funny. Looks like the flag is there, and given that the latitude is `77` and the longitude is `172`, we already have the flag.
