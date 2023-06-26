#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	struct flock filelock;
	filelock.l_type=(strcmp(s[1],"r"))?F_WRLCK:F_RDLCK;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;
	fd=open(s[2], O_RDWR);
	if(fcntl(fd, F_SETLK, &filelock)==-1)
	{
		perror("fcntl failed\n");
		exit(1);
	}
	printf("success\n");
	exit(0);
}

