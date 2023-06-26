#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	int i=0;
	srand(10);
	for(;i<10;i++)
	{
		printf("%d\n",rand()%100);
	}
}
