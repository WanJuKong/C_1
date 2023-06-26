#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(void)
{
	printf("Running ls with execl\n");
	execl("/bin/ls","ls",(char *)0);
	printf("execl failed to run ls\n");
	exit(0);
}

