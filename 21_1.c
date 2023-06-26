#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(void)
{
	int fd1,fd2;
	fd1=open("test1.txt",O_RDONLY);
	fd2=open("test2.txt",O_WRONLY);
	printf("test1: %d\ntest2: %d",fd1,fd2);
	close(fd1);
	close(fd2);
}
