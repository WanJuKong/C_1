#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	if((fd=fopen("nodata",O_RDONLY))==-1)
	{
		if(errno==ENOENT)
			printf("error %d",errno);
		else
			printf("error?? %d",errno);
		exit(1);
	}
	exit(0);
}
