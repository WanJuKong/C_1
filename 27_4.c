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
	int sockfd, recvlen, servlen;
	struct sockaddr_in servaddr;
	char sendbuffer[size], recvbuffer[size];
	if(a!=2)
		exit(1);
	if((sockfd=socket(AF_INET, SOCK_DGRAM, 0))==-1)
	{
		perror("sock failed");
		exit(1);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(s[1]);
	servaddr.sin_port=htons(port);
	while(1)
	{
		printf("input sending message >>> ");
		fgets(sendbuffer, size, stdin);
		if(!strncmp(sendbuffer,"quit",4))
			break;
		if(sendto(sockfd, sendbuffer,strlen(sendbuffer),0,(struct sockaddr*)&servaddr, sizeof(servaddr))!=strlen(sendbuffer))
		{
			perror("sendto failed");
			exit(1);
		}
		servlen=sizeof(servlen);
		if((recvlen=recvfrom(sockfd, recvbuffer, size-1, 0, (struct sockaddr*)&servaddr, &servlen))!=strlen(sendbuffer))
		{
			perror("recvfrom failed");
			exit(1);
		}
		recvbuffer[recvlen]='\0';
		printf("received %s\n", recvbuffer);
	}
	close(sockfd);
	exit(0);
}
