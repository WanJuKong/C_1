#include <stdio.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	FILE *write_fp;
	char buffer[256];
	if((write_fp=popen(s[1],"w"))==NULL)
	{
		perror("popen failed");
		exit(1);
	}
	sprintf(buffer, "Linux c programming\n");
	fprintf(write_fp, buffer);
	pclose(write_fp);
	exit(0);
}
