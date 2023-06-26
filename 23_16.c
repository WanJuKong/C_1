#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *envp[]={"USER=juwan", "PATH=/dir_rename", (char *)0};

void main(void)
{
	printf("Running ls with execle\n");
	execle("/bin/ls","ls",(char *)0, envp);
	printf ("execle failed to run ls\n");
	exit(0);
}

