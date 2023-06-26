#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define max 1024

void main(int a, char *s[])
{
	int fd1, fd2, count;
	char buf[max];
	if(a!=3)
		exit(1);
	if((fd1=open(s[1],O_RDONLY))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if((fd2=creat(s[2],0644))==-1)
	{
		perror("creat failed");
		exit(1);
	}
	while ((count=read(fd1,buf,max))>0)
	{
		if(write(fd2,buf,count)!=count)
		{
			perror("write failed");
			exit(1);
		}
	}
	close(fd1);
	close(fd2);
	exit(0);
}
