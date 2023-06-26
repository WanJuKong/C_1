#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	char *value;
	setenv("HOME","/home/juwan/first",0);
	value=getenv("HOME");
	printf("[setenv overwrite: 0] HOME: %s\n",value);
	setenv("HOME","/home/juwan/first",1);
	value=getenv("HOME");
	printf("[setenv overwrite: 1] HOME: %s\n",value);
	exit(0);
}
	
