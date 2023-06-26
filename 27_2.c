#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define port 7777
#define size 1024

void main(int a, char *s[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char sendbuffer[size], recvbuffer[size];
	int recvlen;
	if(a!=2)
	{
		fprintf(stderr, "Usage: %s IP_address\n", s[0]);
		exit(1);
	}
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0))==-1)
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
		perror("connect failed");
		exit(1);
	}
	while(1)
	{
		printf("input sending message >>> ");
		fgets(sendbuffer,size, stdin);
		if(!strncmp(sendbuffer,"quit", 4))
			break;
		if(send(sockfd, sendbuffer, strlen(sendbuffer), 0) != strlen(sendbuffer))
		{
			perror("send failed");
			exit(1);
		}
		if((recvlen=recv(sockfd, recvbuffer, size-1, 0)) <=0)
		{
			perror("recv failed");
			exit(1);
		}
		recvbuffer[recvlen]='\0';
		printf("received: %s\n", recvbuffer);
	}
	close(sockfd);
	exit(0);
}

