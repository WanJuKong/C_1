#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define max 10

void main(void)
{
	int fd, count;
	char buf[max];
	if((fd=open("alphabet",O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	lseek(fd,5,SEEK_SET);
	count=read(fd,buf,max);
	write(STDOUT_FILENO,buf,count);
	close(fd);
	exit(0);
}
