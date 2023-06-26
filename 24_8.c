#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void sig(int sg);
void main(void)
{
	struct sigaction act;
	act.sa_handler=sig;
	sigfillset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGINT,&act, NULL);
	printf ("call sigaction\n");
	while(1)
	{
		sleep(5);
	}
}

void sig(int sg)
{
	printf("strat\n");
	sleep(3);
	printf("done\n");
}

