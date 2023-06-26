#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define max 100

void main(void)
{
	char buffer[max];
	int n;
	alarm(10);
	n=read(0,buffer,max);
	alarm(0);
	write(1, buffer,n);
	exit(0);
}
