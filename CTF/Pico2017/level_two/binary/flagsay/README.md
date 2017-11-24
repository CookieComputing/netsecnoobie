# Flagsay 1

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33192473-deb0f710-d090-11e7-8b3d-2ae5b915403b.png)

When running the program, we get something like this:

![image](https://user-images.githubusercontent.com/24576987/33192927-e702642e-d092-11e7-9fd6-bfff37312aad.png)

Interesting. This flag takes whatever our input is and then displays something. Is there another unintended side effect somewhere? Let's look at the source code:

```C
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #define FIRSTCHAROFFSET 129
    #define LINELENGTH 35
    #define NEWLINEOFFSET 21
    #define LINECOUNT 6

    #define BUFFLEN 1024

    char flag[] = "               _                                        \n"
                  "              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     \n"
                  "             //                                   /     \n"
                  "            //                                   /      \n"
                  "           //                                   /       \n"
                  "          //                                   /        \n"
                  "         //                                   /         \n"
                  "        //                                   /          \n"
                  "       //___________________________________/           \n"
                  "      //                                                \n"
                  "     //                                                 \n"
                  "    //                                                  \n"
                  "   //                                                   \n"
                  "  //                                                    \n"
                  " //                                                     \n";

    char commandBase[] = "/bin/echo \"%s\"\n";

    void placeInFlag(char * str){
        char * ptr = flag + FIRSTCHAROFFSET;
        char * lastInLine = ptr + LINELENGTH;
        size_t charRemaining = strlen(str);
        size_t linesDone = 0;
        while(charRemaining > 0 && linesDone < LINECOUNT){
            if(ptr == lastInLine){
                ptr += NEWLINEOFFSET;
                lastInLine += NEWLINEOFFSET + LINELENGTH;
                linesDone++;
                continue;
            }
            ptr[0] = str[0];
            ptr++;
            str++;
            charRemaining--;
        }
        
    }


    int main(int argc, char **argv){
        size_t flagSize = strlen(flag) + 1; //need to remember null terminator
        char * input = (char *)malloc(sizeof(char) * flagSize);
        input[flagSize-1] = '\x0';
        fgets(input, flagSize, stdin);
        char * temp = strchr(input, '\n');
        if(temp != NULL){
            temp[0] = '\x0';
        }
        placeInFlag(input);

        size_t commandLen = flagSize + strlen(commandBase) + 1;
        char * command = (char *)malloc(sizeof(char) * commandLen);
        snprintf(command, commandLen, commandBase, flag); 
        system(command);

        free(input);
        free(command);
    }
```

A couple of interesting points:
`char commandBase[] = "/bin/echo \"%s\"\n";`
`snprintf(command, commandLen, commandBase, flag);`
`system(command)`

`snprintf()` will print the results of `commandBase` into `command`, which will then be executed into `system()`. If we can get `command` to print out the results of flag, then we are set. But how can we do that?

It turns out that there is a form of command injection here, where you can actualy abuse the `%s` alongside the `snprintf()` into executing another command.

Here is the payload I used:
![image](https://user-images.githubusercontent.com/24576987/33193028-ac008620-d093-11e7-8e13-07930468ec00.png)

An explanation:
`"` will cause `echo` to only see ""
`;` ends the echo argument and allows me to do other interesting things
'cat flag.txt` lets me see the flag with the current permissions

And we've done it!
