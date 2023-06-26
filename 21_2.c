#include <fcntl.h>
#include <unistd.h>
#define  BUFFSIZE 1024

void main(void)
{
	int fd1, fd2;
	ssize_t n;
	char buf[BUFFSIZE];
	
	fd1=open("test1.txt", O_RDONLY);
	fd2=open("test2.txt", O_WRONLY);
	n=read(fd1, buf, BUFFSIZE);
	write(fd2,buf,n);
	close(fd1);
	close(fd2);
}
