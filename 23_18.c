#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(void)
{
	char *arg[] = {"ls", (char *)0};
	printf("running ls with execvp\n");
	execvp("ls",arg);
	printf("execvp failed torun ls\n");
	exit(0);
}
