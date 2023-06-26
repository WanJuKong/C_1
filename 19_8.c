#include <stdio.h>
#include <stdlib.h>
void a(int e);
void main(void)
{
	a(7==7);
	printf("y\n");
	a(3==1);
	printf("N\n");
}

void a(int e)
{
	if(!(e))
	{
		printf("%s:%d:failed.\n",__FILE__, __LINE__);
		abort();
	}
}
