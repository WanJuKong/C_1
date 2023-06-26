#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define size 1024

void main(void)
{
	int shmid;
	void *shmaddr;
	struct shmid_ds shm_stat;
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
	printf("data read from shared memory: %s\n", (char *)shmaddr);
	if(shmctl(shmid, IPC_STAT, &shm_stat)==-1)
	{
		perror("shmdt failed");
		exit(1);
	}
	if(shmdt(shmaddr)==-1)
	{
		perror("shmctl failed");
		exit(1);
	}
	kill(shm_stat.shm_cpid, SIGINT);
	exit(0);
}
