#include <stdio.h>
#include <stdlib.h>

void f3(void);
void f2(void);
void f1(void);

void main(void)
{
	atexit(f1);
	atexit(f2);
	atexit(f3);
	exit(0);
}

void f2(void)
{
	printf("f2");
}

void f1(void)
{
	printf("f1");
}

void f3(void)
{
	printf("f3");
}

