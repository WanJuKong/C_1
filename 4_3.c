#include <stdio.h>
void main()
{
	float arr[3];
	int i;
	for (i=0;i<3;i++)
	{
		printf("arr[%d]: %u\n", i, &arr[i]);
	}
	printf("\n");
}
