#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void main(int a, char *s[])
{
	int fd;
	if((fd=creat(s[1],0644))==-1)
	{
		perror("creat failed");
		exit(1);
	}
	write(fd, "abcdefghijklmnopqrstuvwxyz", 26);
	if(lseek(fd, 30, SEEK_SET)==-1)
	{
		perror("lseek failed");
		exit(1);
	}
	write(fd, "ABCD", 4);
	close(fd);
	exit(0);
}
