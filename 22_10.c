#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

void main(void)
{
	DIR *dp;
	if(mkdir("dir2",0755)==-1)
	{
		perror("mkdir failed");
		exit(1);
	}
	dp=opendir("dir");
	closedir(dp);
	exit(0);
}
