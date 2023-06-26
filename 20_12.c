#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char *home_dir;
	if((home_dir=getenv("HOME"))!=NULL)
	{
		printf("home directory: %s\n",home_dir);
	}
	putenv("HOME=/home/juwan/first");
	if((home_dir=getenv("HOME"))!=NULL)
	{
		printf("home directory: %s\n",home_dir);
	}
}
