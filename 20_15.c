#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	char *value;
	if((value=getenv("HOME"))!=NULL)
		printf("HOME: %s\n",value);
	else
		printf("HOME: no value");
	unsetenv("HOME");
	if((value=getenv("HOME"))!=NULL)
		printf("HOME: %s\n",value);
	else
		printf("HOME: no value");
	exit(0);
}

