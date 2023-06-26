#include <stdio.h>
#include <stdlib.h>
extern char **environ;
void main(void)
{
	char **env = environ;
	printf("my environment variables are:\n");
	while(*env)
	{
		printf("%s\n", *(env++));
	}
	exit(0);
}

