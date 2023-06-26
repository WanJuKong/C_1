#include <stdio.h>
#include <stdlib.h>
void main()
{
	char *pt;
	printf("%g\n",strtod("-474.14@SDFa",&pt));
	printf("%s",pt);
}
