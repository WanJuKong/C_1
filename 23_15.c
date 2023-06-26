#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(void)
{
	printf("Running ls with execlp\n");
	execlp("ls","ls",(char *)0);
	printf("execlp failed to run ls\n");
	exit(0);
}
