#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void main(void)
{
	struct sigaction act;
	act.sa_handler=SIG_IGN;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGINT, &act, NULL);
	while(1){
		printf("Hi\n");
		sleep(1);
	}
}
