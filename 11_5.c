#include <stdio.h>
int main(void)
{
	FILE *fp;
	fp=fopen("hi","r");
	if(fp==NULL)
	{
		printf("file not found\n");
		return 0;
	}
	fclose(fp);
}
