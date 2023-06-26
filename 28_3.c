#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define port 7800
#define size 1024
void signal_h(int sig);
int sockfd;

void main(int a, char *s[])
{
	struct sockaddr_in servaddr;
	char sendbuf[size],recvbuf[size];
	int recvlen;
	pid_t pid;
	if(a!=2)
		exit(1);
	if((sockfd-socket(AF_INET, SOCK_STREAM, 0))==-1)
	{
		perror("sock failed");
		exit(1);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(s[1]);
	servaddr.sin_port=htons(port);
	if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))==-1)
	{
		perror("conenect failed");
		exit(1);
	}
	switch(pid=fork())
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			signal(SIGINT, signal_h);
			while(1)
			{
				if((recvlen=recv(sockfd, recvbuf,size,0))==-1)
				{
					perror("recv failed");
					exit(1);
				}
				recvbuf[recvlen]='\0';
				printf("%s\n", recvbuf);
			}
			break;
		default:
			while(1)
			{
				fgets(sendbuf, size, stdin);
				if(!strncmp(sendbuf, "quit", 4))
				{
					kill(pid, SIGINT);
					break;
				}
				if(send(sockfd, sendbuf,strlen(sendbuf),0)!=strlen(sendbuf))
				{
					perror("send failed");
					exit(1);
				}
			}
	}
	close(sockfd);
	exit(0);
}

void signal_h(int sig)
{
	close(sockfd);
	exit(0);
}

