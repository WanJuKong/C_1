#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main(void)
{
	signal(SIGINT,SIG_IGN);
	while (1)
	{
		printf("hi\n");
		sleep(1);
	}
}
