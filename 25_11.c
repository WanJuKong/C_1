#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define size 4

void main(void)
{
	char *arg[3]={"abc", "def", "ghi"};
	char buffer[size];
	int pipes[2], i;

	if(pipe(pipes)==-1)
	{
		perror("pipe failed");
		exit(1);
	}
	if(fork())
	{
		close(pipes[0]);
		for(i=0; i<3; i++)
		{
			write(pipes[1], arg[i], size);
			printf("parent process write to pipe: %s\n",arg[i]);
		}
	}
	else
	{
		close(pipes[1]);
		for(i=0; i<3; i++)
		{
			read(pipes[0], buffer, size);
			printf("child process read from pipe: %s\n", buffer);
		}
	}
	exit(0);
}
