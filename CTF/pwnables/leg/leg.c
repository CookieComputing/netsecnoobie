#include <stdio.h>
#include <fcntl.h>
int key1(){
	asm("mov r3, pc\n"); //save IP to r3
}
int key2(){
	asm(
	"push	{r6}\n" // store r6 value
	"add	r6, pc, $1\n" // r6 is now pc + 1
	"bx	r6\n" //call on pc + 1
	".code   16\n" //sets it to Thumb
	"mov	r3, pc\n" //copys the current pc to r3
	"add	r3, $0x4\n"// adds 4 bytes to r3
	"push	{r3}\n" //pushes on to stack
	"pop	{pc}\n" //returns to r3 on stack
	".code	32\n" //now interprets as 32 bit val
	"pop	{r6}\n"//pushes onto r6
	);
}
int key3(){
	asm("mov r3, lr\n"); //moves the return addr to r3
                        // lr holds the caller's return address
}
int main(){
	int key=0;
	printf("Daddy has very strong arm! : ");
	scanf("%d", &key);
	if( (key1()+key2()+key3()) == key ){
		printf("Congratz!\n");
		int fd = open("flag", O_RDONLY);
		char buf[100];
		int r = read(fd, buf, 100);
		write(0, buf, r);
	}
	else{
		printf("I have strong leg :P\n");
	}
	return 0;
}
