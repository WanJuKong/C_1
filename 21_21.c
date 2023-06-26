#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	if((fd=open(s[1], O_WRONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if(ftruncate(fd,150)==-1)
	{
		perror("ftruncate failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
