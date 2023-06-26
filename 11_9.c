#include <stdio.h>
#define MAX 1024
void main(void)
{
	FILE *fp;
	char buffer[MAX];
	int ch,chk=0;
	fp=fopen("source","r");
	while ((ch=fgetc(fp))!=EOF)
	{
		if(ch=='L')
		{
			chk=1;
			break;
		}
	}
	if(chk==1)
	{
		ungetc(ch,fp);
		fgets(buffer,MAX,fp);
		printf("%s\n",buffer);
	}
	else
		puts("not found");
}
