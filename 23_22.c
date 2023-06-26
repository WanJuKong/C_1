#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *envp[]={"USER=juwan","PATH=.",(char *)0};
void main(void)
{
	char *arg[]={"23_21",(char*)0};
	printf("Running");
	execve("./23_21", arg, envp);
	printf("failed");
	exit(0);
}
