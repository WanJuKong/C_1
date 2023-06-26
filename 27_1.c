#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define port 7777
#define max 5
#define size 1024

void main(void)
{
	int servsockfd;
	int clntsockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in clntaddr;
	char recvbuffer[size];
	int clntlen;
	int recvlen;
	if((servsockfd=socket(AF_INET, SOCK_STREAM, 0))==-1)
	{
		perror("sock failed");
		exit(1);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);
	if(bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))==-1)
	{
		perror("bind failed");
		exit(1);
	}
	if(listen(servsockfd, max)==-1)
	{
		perror("listen failed");
		exit(1);
	}
	while(1)
	{
		clntlen = sizeof(clntaddr);
		if((clntsockfd=accept(servsockfd, (struct sockaddr*)&clntaddr, &clntlen))==-1)
		{
			perror("accept failed");
			exit(1);
		}
		while(1)
		{
			if((recvlen=recv(clntsockfd, recvbuffer, size-1,0))==-1)
			{
				perror("recv failed");
				exit(1);
			}
			if(recvlen==0)
				break;
			recvbuffer[recvlen]='\0';
			printf("received: %s\n", recvbuffer);
			if(send(clntsockfd, recvbuffer, recvlen, 0)!=recvlen)
			{
				perror("send failed");
				exit(1);
			}
		}
		close(clntsockfd);
	}
}


