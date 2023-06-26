#include <stdio.h>
void main(void)
{
	FILE *fp;
	if((fp=fopen("nodata","r"))==NULL)
	{
		perror("E");
	}
}
