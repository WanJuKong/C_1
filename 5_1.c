#include <stdio.h>
void val(int x,int y);
void addr(int *x,int *y);

void main()
{
	int a=7,b=11;
	val(a,b);
	printf("%d %d\n",a,b);
	addr(&a,&b);
	printf("%d %d\n",a,b);
}

void val(int x,int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}

void addr(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

