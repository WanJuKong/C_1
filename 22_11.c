#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
void main(void)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp=opendir("."))==NULL)
	{
		perror("opendir failed");
		exit(0);
	}
	while(dirp=readdir(dp))
	{
		printf("%s ", dirp->d_name);
	}
	printf("\n");
	closedir(dp);
	exit(0);
}
