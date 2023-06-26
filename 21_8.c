#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 10

void main(void)
{
	int fd;
	char buf1[MAX],buf2[MAX];
	if((fd=open("alphabet",O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	read(fd,buf1,MAX);
	read(fd,buf2,MAX);
	printf("buf1[0]: %c\nbuf2[0]: %c\n",buf1[0],buf2[0]);
	close(fd);
	exit(0);
}
