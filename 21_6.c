#include <fcntl.h>
#include <stdlib.h>

void main(void)
{
	int fd;
	if((fd=open("test1.txt",O_WRONLY|O_CREAT|O_TRUNC,0644))==-1)
	{
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
