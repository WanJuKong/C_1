#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define max 100

void main(void)
{
	int fd, i;
	char buf[max];
	long int length = 0;
	if((fd=open("alphabet",O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	while((i=read(fd,buf,max))>0)
		length+=i;
	printf("total alphabet: %ld\n",length);
	close(fd);
	exit(0);
}
