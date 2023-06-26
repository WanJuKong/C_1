#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
void main(int a, char *s[])
{
	int fd;
	struct flock filelock;
	filelock.l_type=F_WRLCK;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;

	fd=open(s[1], O_RDWR);

	if(fcntl(fd, F_SETLK, &filelock)==-1)
	{
		fcntl(fd, F_GETLK, &filelock);
		fprintf(stderr,"%s locked by %d\n",s[1], filelock.l_pid);
		exit(1);
	}
	exit(0);
}


