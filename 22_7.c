#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
void main(void)
{
	if(mkdir("dir",0755)==-1)
	{
		perror("mkdir failed");
		exit(1);
	}
	if(rmdir("dir")==-1)
	{
		perror("rmdir failed");
		exit(2);
	}
	exit(0);
}

