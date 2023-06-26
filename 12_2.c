#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(void)
{
	div_t r1;
	ldiv_t r2;
	r1= div(12345,2345);
	r2= ldiv(123456789,12345678);
	printf("%d,%d\n",r1.quot,r1.rem);
	printf("%ld,%ld\n",r2.quot,r2.rem);
	printf("%g\n",fmod(23.456, 2.345));
}
