#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void main(int a,char *s[])
{
	int i;
	struct stat st;
	for(i=1; i<a; i++)
	{
		if(stat(s[i], &st)==-1)
		{
			perror("stat failed");
			exit(1);
		}
		printf("%s\'s mode: %x\n",s[i],st.st_mode);
	}
	exit(0);
}

