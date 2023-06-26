#include <stdio.h>
#include <string.h>
void main(void)
{
	char str[100]="first";
	while('a')
	{
		printf("%s: ",str);
		scanf("%s", str);
		if(!strcmp(str,"quit"))
			break;
	}
}
