#include <stdio.h>
void main(void)
{
	FILE *fp;
	int i;
	float f;
	char str[256];
	fp=fopen("data","w");
	fprintf(fp,"%d %g %s\n",123,12.345,"Hello");
	fclose(fp);
	fp=fopen("data","r");
	fscanf(fp,"%d %g %s",&i,&f,str);
	printf("%d %g %s \n",i,f,str);
	fclose(fp);
}
