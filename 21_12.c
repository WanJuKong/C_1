#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define max 1024
void main(void)
{
	int count;
	char buf[max];
	while((count=read(STDIN_FILENO,buf,max))>0)
	{
		if(write(STDOUT_FILENO, buf, count)!=count)
		{
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
