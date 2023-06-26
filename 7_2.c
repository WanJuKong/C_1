#include <stdio.h>
#define MAX(A,B) A>B?A:B
void main()
{
	int i,j;
	printf("Input two integer >>> ");
	scanf("%d %d",&i,&j);
	printf("max number: %d",MAX(i,j));
}
