#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main(void)
{
	int i=0;
	srand((unsigned)time(NULL));
	for(;i<10;i++)
	{
		printf("%d\n",rand()%100);
	}
}
