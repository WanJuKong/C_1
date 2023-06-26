#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void main(void)
{
	if(chroot("/home/first")==-1)
	{
		perror("chroot failed");
		exit(1);
	}
	if(chdir("/")==-1)
	{
		perror("chdir failed");
		exit(1);
	}
	if(mkdir("rootsub",0777)==-1)
	{
		perror("mkdei failed");
		exit(1);
	}
	exit(0);
}

