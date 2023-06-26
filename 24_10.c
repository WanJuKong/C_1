#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig(int sg);
int sig_count=0;
void main(void)
{
	struct sigaction new_act;
	struct sigaction old_act;
	new_act.sa_handler=sig;
	sigemptyset(&new_act.sa_mask);
	new_act.sa_flags==0;
	sigaction(SIGINT,&new_act,&old_act);
	while(1)
	{
		printf("waiting signal\n");
		sleep(1);
		if(sig_count==3)
			sigaction(SIGINT,&old_act,NULL);
	}
}

void sig(int sg)
{
	sig_count++;
	printf("signal: %d\n",sig_count);
}

				
