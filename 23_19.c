#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *envp[]={"USER=juwan","PATH=/first/dir_rename",(char *)0};

void main(void)
{
	char *arg[] = {"ls", (char *)0};
	printf("running ls with excve\n");
	execve ("/bin/ls", arg, envp);
	printf("execve failed to run ls\n");
	exit(0);
}
