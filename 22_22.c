#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void main(int a, char *s[])
{
	struct stat st;
	if(stat(s[1], &st)==-1)
	{
		perror("stat failed");
		exit(1);
	}
	if(chown(s[2],st.st_uid,st.st_gid)==-1)
	{
		perror("chown failed");
		exit(1);
	}
	exit(0);
}

