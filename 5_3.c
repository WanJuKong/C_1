#include <stdio.h>
void func(void);
int count=0;
void main()
{
	int i=0;
	for(;i<10;i++)
		func();
	printf("count: %d",count);
}
