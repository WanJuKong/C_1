#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void main(void)
{
	int fd;
	if((fd=dup(1))==-1)
	{
		perror("dup failed");
		exit(1);
	}
	write(fd,"ABCD", 5);
	exit(0);
}
