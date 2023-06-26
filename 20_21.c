#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <string.h>

void main(void)
{
	uid_t uid;
	gid_t gid;
	struct passwd *pw;
	struct group *pg;
	int i;
	uid=getuid();
	pw=getpwuid(uid);
	gid=getgid();
	pg=getgrgid(gid);
	printf("uid=%d(%s) groups=",gid,pg->gr_name);
	while(pg=getgrent())
	{
		for(i=0;pg->gr_mem[i]!=NULL;i++)
		{
			if(!strcmp(pw->pw_name,pg->gr_mem[i]))
				printf("%d(%s) ",pg->gr_gid, pg->gr_name);
		}
	}
	printf("\n");
	exit(0);
}
