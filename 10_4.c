#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	char *ptr;
	int i;
	if ((ptr=(char *)malloc(10))==NULL)
		exit(1);
	for(i=0;1<9;i++)
		ptr[i]='a';
	ptr[i]='\0';
	printf("%s\n",ptr);
	free(ptr);
}
