#include <stdio.h>
#define MAX 20

void main()
{
	int i, num;
	int arr[MAX];
	printf("input number of data >>> ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("%dth number >>> ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\ninput data\n");
	for(i=0;i<num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nReverse data\n");
	for(i=num-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
