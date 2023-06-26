#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#define max 100
void main(int a, char *s[])
{
	char name[max];
	getcwd(name, max);
	printf("directory name: %s\n",name);
	chdir("..");
	getcwd(name, max);
	printf("directory name: %s\n",name);
	rmdir(s[1]);
	exit(0);
}
