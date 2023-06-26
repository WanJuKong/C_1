#include <fcntl.h>
#include <stdlib.h>

void main(void)
{
	int fd;
	if((fd=open("test1.txt",O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	close(fd);
	exit(0);
}

