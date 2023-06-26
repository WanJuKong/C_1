#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#define SIZE 128
#define FIFO "fifo"

void main(int a, char *s[])
{
	int fd,i;
	char buffer[SIZE];
	if((fd=open(FIFO, O_WRONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	for(i=1; i<a; i++)
	{
		strcpy(buffer, s[i]);
		if(write(fd, buffer, SIZE)==-1)
		{
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
