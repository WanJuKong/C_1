#include <stdio.h>
#define NAME
void main()
{
#ifdef NAME
	printf("name defined");
#endif
#ifndef NAME
	printf("name undefined");
#endif
#ifndef ADD
	printf("address undefined");
#endif
}
