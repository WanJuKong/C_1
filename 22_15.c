#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#define max 512

void main(int a, char *s[])
{
	DIR *dp;
	struct dirent *drip;
	char *dir, filename[max], list[max], buf[max];
	struct stat st;
	int index, i;

	dir=(a==1?".":s[1]);
	if((dp=opendir(dir))==NULL)
	{
		perror("opendir failed");
		exit(1);
	}
	while(drip=readdir(dp))
	{
		index=0;
		if(!strncmp((*drip).d_name, ".",1))
			continue;
		sprintf(filename, "%s/%s", dir, (*drip).d_name);
		if(lstat(filename,&st)==-1)
		{
			perror("stat failed");
			exit(1);
		}
		switch(st.st_mode & S_IFMT)
		{
			case S_IFREG:
				list[index++]='-';
				break;
			case S_IFDIR:
				list[index++]='d';
				break;
			case S_IFIFO:
				list[index++]='p';
				break;
			case S_IFLNK:
				list[index++]='l';
		}
		for(i=0;i<3;i++)
		{
			list[index++]=((st.st_mode&(S_IREAD>>i*3))?'r':'-');
			list[index++]=((st.st_mode&(S_IWRITE>>i*3))?'w':'-');
			list[index++]=((st.st_mode&(S_IEXEC>>i*3))?'x':'-');
		}
		list[index]='\0';
		printf("%s %s\n", buf, (*drip).d_name);
	}
	closedir(dp);
	exit(0);
}

