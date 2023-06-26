#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void main(int a, char *s[])
{
	if(remove(s[1])==-1)
	{
		perror("remove failed");
		exit(1);
	}
	printf("remove %s\n",s[1]);
	exit(0);
}

