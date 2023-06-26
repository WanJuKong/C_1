#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(void)
{
	int *ptr;
	if((ptr=(int *)malloc(10))==NULL)
		exit(1);
	memset(ptr,'a',9);
	ptr[9]='\0';
	printf("%s\n",ptr);
	free(ptr);
}
