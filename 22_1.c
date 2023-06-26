#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
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
	printf("%ld byte\nuser id: %d\ngroup id: %d\nmodify time: %s",st.st_size, st.st_uid, st.st_gid, ctime(&st.st_mtime));
	exit(0);
}

