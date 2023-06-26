#include <stdio.h>
#include <stdlib.h>

void func(void);

void main(int a, char *s[])
{
	atexit(func);
	if(!atoi(s[1]))
		abort();
	exit(0);
}
void func(void)
{
	printf("run function\n");
}
