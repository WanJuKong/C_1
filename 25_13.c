#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#define size 128
#define FIFO "fifo"

void main(int a, char *s[])
{
	int fd;
	char buffer[size];
	if(mkfifo(FIFO,0666)==-1)
	{
		perror("mkfifo failed");
		exit(1);
	}
	if((fd=open(FIFO, O_RDWR))==-1)
	{
		perror("open failed");
		exit(1);
	}
	while(1)
	{
		if(read(fd, buffer, size)==-1)
		{
			perror("read failed");
			exit(1);
		}
		if(!strcmp(buffer, "quit"))
			exit(0);
		printf("receive message: %s\n", buffer);
	}
}
