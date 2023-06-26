#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(void)
{
	char *arg[] ={"ls", (char *)0};
	printf("Running  ls with execv\n");
	execv("/bin/ls", arg);
	printf("execv failed to run ls\n");
	exit(0);
}
