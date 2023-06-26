#include <stdio.h>
#define DAY 365
#define TIME 24
#define MINUTE 60
#define SECOND 60
void main()
{
	long int sec;
	sec=DAY*TIME*MINUTE*SECOND;
	printf("1 year is %ld second\n",sec);
}
