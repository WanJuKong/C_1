#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#define size 124

void sig_h(int sig);

struct{
	long type;
	char data[size];
}msg_data={1, "Linux programming"};
int msqid;

void main(void)
{
	if(msqid =msgget((key_t)1234, IPC_CREAT|0666)==-1)
	{
		perror("msgget failed");
		exit(1);
	}
	if(msgsnd(msqid,&msg_data, strlen(msg_data.data), 0)==-1)
	{
		perror("msgsnd failed");
		exit(1);
	}
	signal(SIGINT, sig_h);
	pause();
}

void sig_h(int sig)
{
	if(msgctl(msqid, IPC_RMID, 0)==-1)
	{
		perror("msgctl failed");
		exit(1);
	}
	exit(0);
}
