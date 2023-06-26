#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define port 7777
#define size 1024
void main(void)
{
	int sockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in clntaddr;
	char recvbuffer[size];
	int clntlen;
	int recvlen;
	if((sockfd=socket(AF_INET, SOCK_DGRAM, 0))==-1)
	{
		perror("sock failed");
		exit(1);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);
	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1)
	{
		perror("bind failed");
		exit(1);
	}
	while(1)
	{
		clntlen=sizeof(clntaddr);
		if((recvlen=recvfrom(sockfd, recvbuffer, size-1,0,(struct sockaddr*)&clntaddr, &clntlen))==-1)
		{
			perror("recvfrom failed");
			exit(1);
		}
		recvbuffer[recvlen]='\0';
		printf("received: %s\n", recvbuffer);
		if(sendto(sockfd, recvbuffer, recvlen, 0, (struct sockaddr*)&clntaddr, sizeof(clntaddr))!=recvlen)
		{
			perror("sendto failed");
			exit(1);
		}
	}
}
