#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main(int a, char *s[])
{
	int fd;
	if(mkdir(s[1], 0755)==-1)
	{
		perror("mkdir failed");
		exit(1);
	}
	if(chdir(s[1])==-1)
	{
		perror("chdir failed");
		exit(1);
	}
	if((fd=open(s[2], O_WRONLY | O_CREAT, 0644))==-1)
	{
		perror("open failed");
		exit(1);
	}
	write(fd,s[3], strlen(s[3]));
	close(fd);
	exit(0);
}

