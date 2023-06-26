#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
void main(void)
{
	FILE *fp;
	if((fp=fopen("nodata","r"))==NULL)
	{
		printf("errno= %d\n",errno);
		exit(1);
	}
	exit(0);
}
