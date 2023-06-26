#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define size 256

void main(void)
{
	int pipes1[2], pipes2[2], length;
	char read_buffer[size], write_buffer[size];
	if(pipe(pipes1)==-1 || pipe(pipes2)==-1)
	{
		perror("pipe failed");
		exit(1);
	}
	if(fork())
	{
		close(pipes1[1]);
		close(pipes2[0]);
		if((length=read(pipes1[0], read_buffer, size))==-1)
		{
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message: ", 18);
		write(STDOUT_FILENO, read_buffer, length);

		sprintf(write_buffer, "Hello client\n");
		write(pipes2[1], write_buffer, strlen(write_buffer));
		wait(NULL);
	}
	else
	{
		close(pipes1[0]);
		close(pipes2[1]);
		sprintf(write_buffer, "hello server\n");
		write(pipes1[1], write_buffer, strlen(write_buffer));
		if((length=read(pipes2[0], read_buffer, size))==-1)
		{
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message: ", 18);
		write(STDOUT_FILENO, read_buffer, length);
	}
	exit(0);
}
