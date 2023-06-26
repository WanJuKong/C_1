#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	kill(atoi(s[1]),SIGKILL);
}

