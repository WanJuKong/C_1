#include <stdio.h>
#include <stdlib.h>
void main()
{
	char *pt;
	printf("%ld\n",strtol("3579",NULL,10));
	printf("%ld\n",strtol("2473",NULL,8));
	printf("%ld\n",strtol("0415",NULL,0));
	printf("%ld\n",strtol("A2C@Aa",&pt,16));
	printf("%s\n",pt);
}
