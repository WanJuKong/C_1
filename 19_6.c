#include <stdio.h>
#define NDEBUG
#include <assert.h>
#include <stdlib.h>
void main(void)
{
	FILE *fp;
	fp=fopen("yesdata","r");
	assert(fp);
	printf("Y");
	fclose(fp);
	fp=fopen("nodata","r");
	assert(fp);
	printf("N");
	exit(0);
}
