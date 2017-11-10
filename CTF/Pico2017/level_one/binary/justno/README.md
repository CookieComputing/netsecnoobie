# JustNo challenge

We are given a binary and also it's source code:

![image](https://user-images.githubusercontent.com/24576987/32644391-53cb2f26-c5af-11e7-9375-0be365c3daf9.png)

Normally, relative pathing is incredibly useful, but the issue with relative pathing is that they can be abused for security purposes. What happens if we create a folder that matches these exact paths, and then we use `ln` to link a file to `auth`?

![image](https://user-images.githubusercontent.com/24576987/32644662-fd43da70-c5b0-11e7-9d49-e9dccb31d0a8.png)

Easy enough!
