#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig(int sg);

void main(void)
{
	signal(SIGINT,sig);
	while(1)
	{
		printf("L\n");
		sleep(1);
	}
}

void sig(int sg)
{
	printf("hello signal: %d\n",sg);
	signal(SIGINT, SIG_DFL);
}
