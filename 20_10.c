#include <stdio.h>
#include <stdlib.h>
extern char **environ;
void main(void)
{
	while(*environ)
		printf("%s\n",*environ++);
}
