#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(void)
{
	printf("%d: %d\n",-345,abs(-345));
	printf("%ld: %ld\n", -123456789, labs(-123456789));
	printf("%g: %g\n",-23.456,fabs(-23.456));
}
