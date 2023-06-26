#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void main(void)
{
	printf("one\n");
	if(fork()==-1)
		perror("fork failed");
	else
		printf ("two\n");
}

