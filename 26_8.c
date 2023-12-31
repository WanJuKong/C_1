#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define size 1024

void main(void)
{
	struct check_data{
		int check;
		char data[size];
	} *shared_data;
	int shmid;
	void *shmaddr;
	char buffer[size];

	if((shmid=shmget((key_t)1234, size, IPC_CREAT|0666))==-1)
	{
		perror("shmid failed");
		exit(1);
	}
	if((shmaddr=shmat(shmid, (void *)0,0))==(void *)-1)
	{
		perror("shmat failed");
		exit(1);
	}
	shared_data=(struct check_data *)shmaddr;
	while(1)
	{
		while(shared_data->check){
			sleep(1);
			printf("waiting...\n");
		}
		printf("input data >>> ");
		fgets(buffer, size, stdin);
		strncpy(shared_data->data, buffer, size);
		shared_data->check=1;
		if(!strncmp(shared_data->data,"quit",4))
			break;
	}
	if(shmdt(shmaddr)==-1)
	{
		perror("shmdt failed");
		exit(1);
	}
	exit(0);
}

