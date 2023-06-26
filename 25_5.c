#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define size 20

void main(int a, char *s[])
{
	int fd, length;
	struct flock filelock;
	char buffer[size];
	filelock.l_type=F_RDLCK;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;

	fd=open(s[1], O_RDWR);
	if (fcntl(fd, F_SETLKW, &filelock)==-1)
	{
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", s[1]);
	length=read(fd, buffer, size);
	write(STDOUT_FILENO,buffer, length);
	printf("unlocked %s", s[1]);
	exit(0);
}
