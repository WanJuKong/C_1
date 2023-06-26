#include <stdio.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void main(void)
{
	gid_t gid;
	struct group *pg;
	int i;
	gid=getgid();
	pg=getgrgid(gid);
	printf("group name: %s\n",pg->gr_name);
	exit(0);
}
