#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main(void)
{
	int count=0;
	while(1)
	{
		printf("HI\n");
		count++;
		if(count==3)
			raise(SIGINT);
		sleep(2);
	}
}
