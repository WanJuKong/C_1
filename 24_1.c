#include <stdio.h>
#include <signal.h>
#define max 64
void main(void)
{
	sigset_t set;
	if(sigemptyset(&set)==-1)
	{
		perror("sigemptyset failed");
		exit(1);
	}
	if(sigaddset(&set,SIGINT)==-1)
	{
		perror("sigaddset failed");
		exit(1);
	}
	if(sigismember(&set,SIGINT))
		printf("SIGINT is a member\n");
	else
		printf("SIGINT is not a member\n");
	exit(0);
}
