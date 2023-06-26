#include <stdio.h>
void main()
{
	int i=10;
	int *path;
	path=&i;
	(*path)++;
	printf("%d\n",i);
}
