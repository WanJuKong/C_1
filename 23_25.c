#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int a, char *s[])
{
	char *str;
	int i=1;
	printf("Running %s...\n",s[1]);
	while(a>i)
	{
		strcat(str, s[i++]);
		strcat(str," ");
	}
	system(str);
	printf("Done");
	exit(0);
}


