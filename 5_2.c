#include <stdio.h>
void func(void);
int count=0;
void main()
{
	int i;
	for(i=0;i<10;i++)
	{
		func();
	}
	printf("count: %d\n", count);
}

void func(void)
{
	count++;
}


