#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define port 7800
#define max 5
#define size 1024

void main(void)
{
	int servsockfd, clntsockfd, clntlen, recvlen;
	struct sockaddr_in servaddr, clntaddr;
	char recvbuf[size], sendbuf[size];

	if((servsockfd=socket(AF_INET, SOCK_STREAM, 0))==-1)
	{
		perror("sock failed");
		exit(1);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family =AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(port);

	if(bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))==-1)
	{
		perror("bind failed");
		exit(1);
	}
	if(listen(servsockfd,max)==-1)
	{
		perror("listen failed");
		exit(1);
	}
	while(1)
	{
		clntlen=sizeof(clntaddr);
		if((clntsockfd=accept(servsockfd, (struct sockaddr*)&clntaddr, &clntlen))==-1)
		{
			perror("accept failed");
			exit(1);
		}
		printf("client is in\n");
		switch(fork())
		{
			case -1:
				perror("fork failed");
				exit(1);
			case 0:
				close(servsockfd);
				while(1)
				{
					if((recvlen=recv(clntsockfd, recvbuf, size, 0))==-1)
					{
						perror("recv failed");
						exit(1);
					}
					if(recvlen==0)
						break;
					recvbuf[recvlen]='\0';
					printf("%s\n", recvbuf);
				}
				close(clntsockfd);
				exit(0);
			default:
				while(1)
				{
					fgets(sendbuf,size,stdin);
					if(send(clntsockfd, sendbuf, strlen(sendbuf), MSG_NOSIGNAL)!=strlen(sendbuf))
					{
						if(errno==EPIPE)
						{
							printf("client is out\n");
							break;
						}
						perror("send failed");
						exit(1);
					}
				}
		}
		close(clntsockfd);
	}
}
