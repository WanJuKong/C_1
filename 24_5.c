#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main(void)
{
	int c=1;
	signal(SIGINT,SIG_IGN);
	while(1)
	{
		printf("hi\n");
		sleep(1);
		if(++c==5)
			signal(SIGINT,SIG_DFL);
	}
}
