#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void main(int a, char *s[])
{
	struct stat st;
	if(stat(s[1],&st)==-1)
	{
		perror("stat failed");
		exit(1);
	}
	printf("user: %s%s%s\n", (st.st_mode & S_IRUSR)?"read ":"",(st.st_mode & S_IWUSR)?"write ":"",(st.st_mode & S_IXUSR)?"execute ":"");
	printf("group: %s%s%s\n", (st.st_mode & S_IRGRP)?"read ":"",(st.st_mode & S_IWGRP)?"write ":"",(st.st_mode & S_IXGRP)?"execute ":"");
	printf("others: %s%s%s\n", (st.st_mode & S_IROTH)?"read ":"",(st.st_mode & S_IWOTH)?"write ":"",(st.st_mode & S_IXOTH)?"execute ":"");
	exit(0);
}
