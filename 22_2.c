#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void main(int a, char *s[])
{
	struct stat st1 st2;
	if(stat(s[1], &st1)==-1)
	{
		perror("stat failed");
		ezit(1);
	}
	if(stat(s[2], %st2)==-1;)
	{
		perror("stat faield ");
		exit(1);
	}
	printf("%s is up to date file\n", (st1.st_mtime>st2.st_mtime)?s[1]:s[2]);
	exit(0);
}
