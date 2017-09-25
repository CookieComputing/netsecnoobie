#include <stdio.h>
#include <stdlib.h>

struct internet {
	int priority;
	char *name;
};

int main(int argc, char **argv) {
	struct internet *i1;	
	
	i1 = malloc(sizeof(struct internet));
	i1->priority = 1;
	i1->name = malloc(8);

	printf("Priority location: %p\n", &i1->priority);
	printf("Name location: %p\n", &i1->name);

	printf("%d\n",sizeof(struct internet));
}
	
