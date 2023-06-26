#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define max 10

void main(void)
{
	int fd;
	char buf[max]="C Program";
	if((fd=open("test3.txt",O_WRONLY|O_CREAT|O_APPEND,0644))==-1)
	{
		perror("open failed");
		exit(1);
	}
	write(fd, buf, max);
	close(fd);
	exit(0);
}
