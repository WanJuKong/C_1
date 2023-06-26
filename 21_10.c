#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void main(void)
{
	int fd;
	char buf[20]="Linux C Programming";
	if((fd=open("test3.txt",O_WRONLY|O_CREAT,0644))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if(write(fd,buf,20)==-1)
	{
		perror("write failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
