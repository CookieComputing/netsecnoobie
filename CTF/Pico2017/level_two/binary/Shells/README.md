# Shells

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33191347-79c346d2-d086-11e7-9a04-4ceae0d3c490.png)

Here is the source code:

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define AMOUNT_OF_STUFF 10

//TODO: Ask IT why this is here
void win(){
    system("/bin/cat ./flag.txt");    
}


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

Interestingly, its nearly the same challenge as before, but there is a big change: You only have 10 bytes, and the `win()` function is enabled.

With the open function address, it is possible to use that function to grab the flag, but it requires a bit of creativity. I actually learned this technique during this CTF and was fortunate enough to use it in another CTF, where I was only given 6 bytes to play with!

The `ret` address in x86 assembly can be used to send whatever is currently on the stack to the `eip`. However, we need to push something to the stack: Why not push the address of `win()` onto the stack?

Let's find win:

`readelf -s ./shells`

![image](https://user-images.githubusercontent.com/24576987/33191421-17260a68-d087-11e7-9839-c9868eb78357.png)

Here is the `win()` address, now we just need to create the shellcode for it.

While it is possible to use `nasm` or `pwntools` to create such a shellcode, Shell-storm has a quick and dirty way of creating shellcode:

![image](https://user-images.githubusercontent.com/24576987/33191442-42b8fa96-d087-11e7-9e61-c04ebd583877.png)

Just plop the code in and get the flag!
