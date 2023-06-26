#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int signal_flag=0;
void sig(int sg);

void main(void)
{
	struct sigaction act;
	if(fork())
	{
		printf("parent process\n");
		act.sa_handler=sig;
		sigemptyset(&act.sa_mask);
		act.sa_flags=0;
		sigaction(SIGINT, &act, NULL);
		pause();
		if(signal_flag)
			printf("signal fired\n");
		exit(0);
	}
	else
	{
		sleep(5);
		kill(getppid(),SIGINT);
		exit(0);
	}
}

void sig(int sg)
{
	signal_flag=1;
}

