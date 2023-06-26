#include <stdio.h>
#include <time.h>
void main(void)
{
	time_t time_now;
	time(&time_now);
	printf("%ld\n",time_now);
}
