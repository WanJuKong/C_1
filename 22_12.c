#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int find_file(char *dir, char *file);

void main(int a, char *s[])
{
	if(find_file(s[1],s[2]))
		printf("found %s\n", s[2]);
	else
		printf("not found %s\n", s[2]);
	exit(0);
}

int find_file(char *dir, char *file)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp=opendir(dir))==NULL)
	{
		perror("opendir failed");
		exit(1);
	}
	while(dirp=readdir(dp))
	{
		if(!strcmp(dirp->d_name, file))
		{
			closedir(dp);
			return 1;
		}
		else
		{
			closedir(dp);
			return(0);
		}
	}
	closedir(dp);
	exit(0);
}
