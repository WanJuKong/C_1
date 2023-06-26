#include <stdio.h>
#include <unistd.h>

void main(int a, char *s[])
{
	int i;
	char *arg[a];
	printf("Runnung %s with execvp\n",s[1]);
	for(i=0;i<a-1;i++)
	{
		arg[i]=(char *)0;
	}
	execvp(s[1],arg);
	printf("failed");
	exit(0);
}
