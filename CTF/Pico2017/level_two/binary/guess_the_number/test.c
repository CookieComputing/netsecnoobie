#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char* argv[]) { 
    uintptr_t val;
    char buf[32] = "";

    setbuf(stdout, NULL);

    printf("Enter your number: ");
    scanf("%32s", buf);
    val = strtol(buf, NULL, 10);
   
    printf("Before: %d\n", val);
    val >>= 4;
    printf("After: %d\n",val);
 
}
