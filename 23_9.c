#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void main(void)
{
	int pid, child_pid, status;
	if ((pid=fork())==-1)
		perror("fork failed");
	else if(pid!=0)
	{
		if((pid=fork())==-1)
			perror("fork failed");
		else if(pid!=0)
		{
			child_pid=wait(&status);
			printf("child[pid: %d] terminated with code %x\n", child_pid, status);
		}
		else
		{
			printf("run child2[pid: %u]\n",getpid());
			exit(3);
		}
	}
	else
	{
		printf("run child1[pid: %u]\n", getpid());
		exit(2);
	}
}
