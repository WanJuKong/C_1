#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void main(void)
{
	if(chmod("test_1.c",0644)==-1)
		perror("chmod failed");
	if(chmod("test_2.c",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)==-1)
		perror("chmod failed");
	exit(0);
}
