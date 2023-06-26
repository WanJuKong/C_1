#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void main(void)
{
	FILE *fp;
	if((fp=fopen("nodata","r"))==NULL)
	{
		fprintf(stderr,"E: %s\n",strerror(errno));
		exit(1);
	}
	exit(0);
}
