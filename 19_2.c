#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
void main(void)
{
	int fd;
	if((fd=open("nodata",O_RDONLY))==-1)
	{
		printf("errno= %d\n",errno);
		exit(1);
	}
	exit(0);
}
