#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void)
{
	int stat;
	if (fork())
	{
		wait(&stat);
		printf("child process terminated with code %x\n", stat);
	}
	else
	{
		alarm(3);
		printf("looping forever...\n");
		while(1)
			;
	}
}
