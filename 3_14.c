#include <stdio.h>
void main(){
	int a,s,max,min;
	printf("\nInput integer1 >>>");
	scanf("%d",&a);
	printf("\nInput integer2 >>>");
	scanf("%d",&s);
	max=(a>s?a:s);
	min=(a<s?a:s);
	printf("\nmax: %d\nmin: %d\n",max,min);
}
