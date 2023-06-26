#include <stdio.h>
void main(void)
{
	int a, *s;
	s=&a;
	scanf("%d %d",&a,s);
	printf("%d, %d\n",a,*s);
	printf("%d\n",*&a);
}

