#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(void)
{
	pid_t pid;
	if((pid=fork())==-1)
		perror("fork failed");
	else if(pid!=0)
		printf("PID is %lu, child process pid is %lu\n", getpid(), pid);
	else
		printf("PID is %lu, parent process pid is %lu\n", getpid(), getppid());
}

