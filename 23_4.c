#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
	pid_t pid;
	if((pid=vfork())==-1)
		perror("vfock failed");
	else if (pid!=0)
		printf("PID is %lu, child process pid is %lu\n", getpid(),pid);
	else
	{
		printf("PID is %lu, parent process pid is %lu\n",getpid(),getppid());
		//exit(0);
	}
}

