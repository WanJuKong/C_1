#include <stdio.h>
#include <string.h>
void main(void)
{
	int i;
	for(i=0;i<125;i++)
	{
		printf("[%03d] %s\n",i,strerror(i));
	}
}	
