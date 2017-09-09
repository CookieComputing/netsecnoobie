# Stack2 - Protostar Challenge

We are given a binary and its source code: 

![image](https://user-images.githubusercontent.com/24576987/30235308-727e82fc-94d5-11e7-9275-3e4648070a6a.png)

From the looks of it, the program requires an environment variable to be set. Even testing the program alone demands it as well: 

![image](https://user-images.githubusercontent.com/24576987/30235323-b480b616-94d5-11e7-9585-33ece4031e5a.png)

An interesting observation reveals the using ```export``` rejects the shell command from being run. ```export``` does not accept commands, so simply setting the variable to the payload works fine.

![image](https://user-images.githubusercontent.com/24576987/30235375-9ea550d0-94d6-11e7-9b4e-aafc1e8c0607.png)

