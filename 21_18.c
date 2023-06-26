#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	off_t fs;
	if((fd=open(s[1],O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if ((fs=lseek(fd,0,SEEK_END))==-1)
	{
		perror("lseek failed");
		exit(1);
	}
	printf("%s\'s size: %ld\n",s[1],fs);
	close(fd);
	exit(0);
}
