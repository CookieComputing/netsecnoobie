# Stack3 - Protostar Challenge

We are given a binary ```stack3``` and its source code:

![image](https://user-images.githubusercontent.com/24576987/30235383-c4fcf58a-94d6-11e7-8ad8-f8b8f8cd1e57.png)

The objective is to control the flow of the program so that the instruction pointer will point to ```win()``` instead of anwhere else. The program uses a function pointer ```fp``` in order to point tothe function. Let's debug the program and see what's going on:

![image](https://user-images.githubusercontent.com/24576987/30235522-15739730-94d7-11e7-9e4b-afb452e85546.png)

After the ```cmp``` instruction, if ```fp``` is not 0, then the program will then set the contents of ```fp``` into the space right below ```esp```, which is then configured so that ```printf()``` can be called with the contents of ```fp``` as its first argument. The contents of ```fp``` are then moved into eax, which is then called.

Obviously, we want to point this ```fp``` variable to ```win()``` so that we can do something that the author may not have intended. Let's do that now:

```perl -e 'print "A"x64 . "\x24\x84\x04\x08"' | ./stack3```

![image](https://user-images.githubusercontent.com/24576987/30235579-d1859e14-94d7-11e7-8973-3b220f08908b.png)

