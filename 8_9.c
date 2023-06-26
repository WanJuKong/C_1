#include <stdio.h>
#include <string.h>
#define MAX 20
void main()
{
	char str[MAX];
	int i=0,j,ch;
	printf("input string >>> ");
	scanf("%s",str);
	for(j=strlen(str)-1;i<j;i++,j--)
	{
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
	printf("reversed: %s",str);
}
