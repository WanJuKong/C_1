#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define size 4

void main(void)
{
	char *arg[3] ={"abc", "def", "ghi"};
	char buffer[size];
	int pipes[2], i;
	if(pipe(pipes)==-1)
	{
		perror("pipe failed");
		exit(1);
	}
	for(i=0; i<3; i++)
		write(pipes[1], arg[i], size);
	for(i=0; i<3; i++)
	{
		read(pipes[0],buffer, size);
		printf("%s\n",buffer);
	}
	exit(0);
}
