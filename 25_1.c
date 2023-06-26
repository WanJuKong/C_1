#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	struct flock filelock;

	filelock.l_type=(!strcmp(s[1],"r"))?F_RDLCK:F_WRLCK;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;

	fd=open(s[2], O_RDWR | O_CREAT, 0666);
	if(fcntl(fd, F_SETLK, &filelock)== -1)
	{
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", s[2]);
	sleep(30);
	printf("unlocked %s\n", s[2]);
	exit(0);
}
