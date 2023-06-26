#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdlib.h>

void main(void)
{
	struct passwd *pw;
	while(pw=getpwent())
		printf("name: %s\nuid: %d\nhome: %s\n",pw->pw_name,pw->pw_uid,pw->pw_dir);
	endpwent();
	exit(0);
}
