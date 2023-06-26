#include <stdio.h>
#include <grp.h>
#include <sys/types.h>
#include <stdlib.h>

void main(void)
{
	struct group *pg;
	int i;
	while(pg=getgrent())
	{
		printf("group name: %s\nmember: ",pg->gr_name);
		for(i=0; pg->gr_mem[i]!=NULL;i++)
			printf("%s ",pg->gr_mem[i]);
		printf("\n\n");
	}
	endgrent();
	exit(0);
}
