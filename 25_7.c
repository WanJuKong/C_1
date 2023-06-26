#include <stdio.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	FILE *read_fp;
	char  buffer[256];
	if((read_fp=popen(s[1], "r"))==NULL)
	{
		perror("popen failed");
		exit(1);
	}
	while(fgets(buffer, sizeof(buffer), read_fp))
		fputs(buffer, stdout);
	pclose(read_fp);
	exit(0);
}
