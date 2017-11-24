# I've got a secret

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33192318-a2e388e8-d08f-11e7-9d8f-837c8b01b2d0.png)

This challenge is a bit tricky as it required me to assume that ASLR was disabled, thus we needed to either use the remote server or to disable ASLR locally. Now, back to the challenge.

![image](https://user-images.githubusercontent.com/24576987/33192338-cdec2b80-d08f-11e7-8bdb-291fc3d86716.png)

The program will spit back whatever you sent to it, but what does that mean for us? Well, the hint implies that `printf()` is vulnerable, which means that we should look into the source code:

Source
```
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>

    #define BUF_LEN 64
    char buffer[BUF_LEN];

    int main(int argc, char** argv) {
        int fd = open("/dev/urandom", O_RDONLY);
        if(fd == -1){
            puts("Open error on /dev/urandom. Contact an admin\n");
            return -1;
        }
        int secret;
        if(read(fd, &secret, sizeof(int)) != sizeof(int)){
            puts("Read error. Contact admin!\n");
            return -1;
        }
        close(fd);
        printf("Give me something to say!\n");
        fflush(stdout);
        fgets(buffer, BUF_LEN, stdin);
        printf(buffer);

        int not_secret;
        printf("Now tell my secret in hex! Secret: ");
        fflush(stdout);
        scanf("%x", &not_secret);
        if(secret == not_secret){
            puts("Wow, you got it!");
            system("cat ./flag.txt");   
        }else{
            puts("As my friend says,\"You get nothing! You lose! Good day, Sir!\"");
        }

        return 0;
    }
```

Something interesting about `printf()` is that `printf()` will comply with any input even if it does not follow the proper format. Something like `printf(buffer)` will still work as it does `printf("%s",buffer)`. I highly recommend looking at the section in `Hacking: The Art of Exploitation` for more details on the `printf()` vulnerability.

Let's see what happens when we try to find the random variable on the stack:

![image](https://user-images.githubusercontent.com/24576987/33192396-5381b7a6-d090-11e7-932c-fd8c2ee2dde7.png)

Aha! So the only random stack object was indeed the answer for the flag! We've done it!
