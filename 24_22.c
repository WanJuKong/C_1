#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_h(int sig);

void main(void)
{
	sigset_t set, oldset;
	struct sigaction act;

	act.sa_handler=signal_h;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGINT, &set, NULL);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	sleep(5);
	sigsuspend(&oldset);
	exit(0);
}

void signal_h(int sig)
{
	printf("signal %d\n", sig);
}

