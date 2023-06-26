#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[],char *envp[])
{
	while(*envp)
		printf("%s\n",*envp++);
}
