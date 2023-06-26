#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#define max 7

void main(void)
{
	char buf[256];
	char *arg[max];
	char *s ,*save;
	static const char delim[]=" \t\n";
	int argv, pid, status;
	while(1)
	{
		printf("myshell: ");
		fgets(buf,256,stdin);
		argv=0;
		s=strtok_r(buf,delim, &save);
		while(s)
		{
			arg[argv++]=s;
			s=strtok_r(NULL,delim,&save);
		}
		arg[argv]=(char *)0;
		if(!strcmp(arg[0],"quit"))
			break;
		if((pid=fork())==-1)
			perror("fork failed");
		else if(pid!=0)
			pid = wait(&status);
		else
			execvp(arg[0],arg);
	}
	exit(0);
}
