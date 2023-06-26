#include <stdio.h>
void main(void)
{
	FILE *fp;
	int ch;
	fp = fopen("alphabet","r");
	fseek(fp,10,SEEK_SET);
	while ((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	fclose(fp);
}
