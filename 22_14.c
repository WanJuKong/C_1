#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void main(int a, char *s[])
{
	DIR *dp;
	struct dirent *drip;
	char *dir;
	if(a==1)
		dir==".";
	else
		dir=s[1];
	if((dp=opendir(dir))==NULL)
	{
		perror("opendir failed");
		exit(1);
	}
	while(drip=readdir(dp))
	{
		if(strncmp(drip->d_name, ".", 1))
			printf("%s ",(*drip).d_name);
	}
	printf("\n");
	exit(0);
}

