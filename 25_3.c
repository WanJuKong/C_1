#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int fd;
	struct flock filelock;
	filelock.l_type=F_WRLCK;
	filelock.l_whence=SEEK_SET;
	filelock.l_start=0;
	fd = open(s[1], O_RDWR);
	switch(fork())
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			filelock.l_len=5;
			if(fcntl(fd, F_SETLKW, &filelock)==-1)
			{
				perror("fcntl failed");
				exit(1);
			}
			printf("child p: locked\n");
			sleep(3);
			filelock.l_type=F_UNLCK;
			if(fcntl(fd, F_SETLK, &filelock)==-1)
			{
				perror("fcntl failed");
				exit(1);
			}
			printf("child p: unlocked\n");
			break;
		default:
			filelock.l_len=10;
			if(fcntl(fd, F_SETLKW, &filelock)==-1)
			{
				perror("fctnl failed\n");
				exit(1);
			}
			printf("parent p: locked\n");
			sleep(3);
			filelock.l_type=F_UNLCK;
			if(fcntl(fd, F_SETLK, &filelock)==-1)
			{
				perror("fcntl failed");
				exit(1);
			}
			printf("parent p: unlocked\n");
			wait(NULL);
	}
	exit(0);
}

