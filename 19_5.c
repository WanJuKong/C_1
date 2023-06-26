#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void main(void)
{
	FILE *fp;
	fp=fopen("yesdeta","r");
	assert(fp);
	printf("y");
	fclose(fp);
	fp=fopen("nodeata","r");
	assert(fp);
	fclose(fp);
	exit(0);
}
