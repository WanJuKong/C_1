#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main(void)
{
	sigset_t set, oldset;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, &oldset);
	printf("block start\n");
	sleep(10);
	sigprocmask(SIG_SETMASK, &oldset, NULL);
	printf("restore to the original state\n");
	sleep(2);
}

