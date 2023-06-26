#include <stdio.h>
void main(void)
{
	FILE *fp;
	int ch='a';
	fp= fopen("source","r");
	fputc(ch,fp);
	if(ferror(fp))
	{
		puts("Error");
	}
	else
		puts("continue");
	clearerr(fp);
	if(ferror(fp))
		puts("Non Error");
	fclose(fp);
}
