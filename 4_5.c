#include <stdio.h>
void main()
{
	int arr[5]={10,20,30,40,50};
	int *path;
	int i;
	for(path=&arr, i=0;i<5;i++)
	{
		printf(" %d\n",path);
		printf("%d\n",*path++);
	}
}
