#include <stdio.h>
#include <stdlib.h>
int max(int n1,int n2);
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage: a.out number1 number2\n");
		exit(1);
	}
	printf("max number: %d\n",max(atoi(argv[1]),atoi(argv[2])));
	exit(0);
}

int max(int n1,int n2)
{
	return (n1>n2?n1:n2);
}
