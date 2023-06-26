#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main(void)
{
	sigset_t set1, set2;
	sigfillset(&set1);
	sigemptyset(&set2);
	sigaddset(&set2, SIGINT);
	sigaddset(&set2, SIGINT);
	sigprocmask(SIG_BLOCK, &set1, NULL);
	printf("block start\n");
	sleep(5);
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	printf ("SIGINT unblock\n");
	while(1)
	{
		printf("hi\n");
		sleep(2);
	}
}

