#include <stdio.h>
#include <signal.h>

void main(void)
{
	sigset_t set;
	if(sigfillset(&set)==-1)
	{
		perror("sigfillset failed");
		exit(1);
	}
	if(sigdelset(&set,SIGPIPE)==-1)
	{
		perror("sigdelset failed");
		exit(1);
	}
	if(sigismember(&set,SIGPIPE))
		printf("SIGPIPE is a member");
	else
		printf("SIGPIPE is not a member");
	exit(0);
}

