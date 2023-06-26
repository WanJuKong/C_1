#include <stdio.h>
#define size 1000
void main()
{
	int i;
	i=size;
	printf("%d",i);
#undef size
#define size 200
	i=size;
	printf("%d",i);
}
