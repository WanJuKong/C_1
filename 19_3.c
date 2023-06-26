#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
void main(void)
{
	double y;
	int i=-1;
	errno=0;
	y=sqrt(i);
	if (errno!=0){
		printf("errno = %d",errno);
		exit(1);
	}
	exit(0);
}
	
