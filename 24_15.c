#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarm_(int sig);

void main(void)
{
	int status;
	struct sigaction act;
	act.sa_handler=alarm_;
	sigemptyset(&act.sa_mask);
	act.sa_flags==0;
	sigaction(SIGALRM,&act,NULL);
	alarm(3);
	while(1){;}
}
void alarm_(int sig)
{
	printf("signal %d\n", sig);
	exit(0);
}

