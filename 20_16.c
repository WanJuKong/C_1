#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
void main(void)
{
	printf("User id: %d\n",getuid());
	printf("Group id: %d\n",getgid());
	exit(0);
}
