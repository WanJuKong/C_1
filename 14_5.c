#include <stdio.h>
#include <time.h>
#include <unistd.h>
void main(void)
{
	time_t old,new;
	time(&old);
	sleep(5);
	time(&new);
	printf("%g\n",difftime(new,old));
}
