#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define size 1024

void sig_h(int  sig);
int shmid;

void main(void)
{
	void * shmaddr;
	if((shmid=shmget((key_t)1234, size, IPC_CREAT|0666))==-1)
	{
		perror("shmid failed");
		exit(1);
	}
	if((shmaddr=shmat(shmid,(void *)0,0))==(void *)-1)
	{
		perror("shmat failed");
		exit(1);
	}
	strcpy((char *)shmaddr, "linux programming");
	if(shmdt(shmaddr)==-1)
	{
		perror("shmdt failed");
		exit(1);
	}
	signal(SIGINT, sig_h);
	pause();
}

void sig_h(int sig)
{
	if(shmctl(shmid, IPC_RMID, 0)==-1)
	{
		perror("shmctl failed");
		exit(1);
	}
	exit(0);
}
