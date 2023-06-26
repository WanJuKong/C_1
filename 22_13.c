#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>

void main(void)
{
	DIR *dp;
	struct dirent *drip;
	if((dp=opendir("."))==NULL)
	{
		perror("opendir failed");
		exit(1);
	}
	while(drip=readdir(dp))
		printf("%s ",(*drip).d_name);
	printf("\n");
	rewinddir(dp);
	while(drip=readdir(dp))
		printf("%s ",(*drip).d_name);
	printf("\n");
	closedir(dp);
	exit(0);
}

