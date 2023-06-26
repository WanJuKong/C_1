#include <stdio.h>
void func(void);
void main()
{
	int i=0;
	for(;i<10;i++)
		func();
}

void func(void)
{
	int auto_val=0;
	static int stat_val=0;
	printf("auto: %d\nstatic: %d\n\n",++auto_val,++stat_val);
}
