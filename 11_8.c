#include <stdio.h>
#define MAX 1024
void main(void)
{
	FILE *ifp, *ofp;
	char buffer[MAX];
	int num;
	ifp=fopen("source","r");
	ofp=fopen("result","w");
	num=fread(buffer,1,MAX,ifp);
	fwrite(buffer,1,num,ofp);
	fclose(ifp);
	fclose(ofp);
}
