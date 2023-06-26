#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	struct flock filelock;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;
	fd=open(s[1], O_RDWR|O_CREAT,0666);
	if(fcntl(fd, F_SETLK, &filelock)==-1)
	{
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", s[1]);
	write(fd, "hi linux", 9);
	sleep(5);
	printf("unlocked %s\n", s[1]);
	exit(0);
}
