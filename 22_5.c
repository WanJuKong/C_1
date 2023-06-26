#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void main(int a, char *s[])
{
	struct stat st;
	if(stat(s[1], &st)==-1)
	{
		perror("stat failed");
		exit(1);
	}
	if (S_ISREG(st.st_mode))
		printf("regular\n");
	else if(S_ISDIR(st.st_mode))
		printf("directory\n");
	else if(S_ISCHR(st.st_mode))
		printf("character\n");
	else if(S_ISBLK(st.st_mode))
		printf("block\n");
	else if(S_ISFIFO(st.st_mode))
		printf("fifo\n");
	exit(0);
}

