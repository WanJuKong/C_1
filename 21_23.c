#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void main(int a, char *s[])
{
	int fd, nfd;
	if((fd=open(s[1], O_WRONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if((nfd=dup(fd))==-1)
	{
		perror("dup failed");
		exit(1);
	}
	if(lseek(nfd, 0, SEEK_END)==-1)
	{
		perror("lseek failed");
		exit(1);
	}
	write(nfd, " ABCD", 5);
	close(fd);
	exit(0);
}
