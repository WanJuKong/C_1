#include <stdio.h>
#include <string.h>
void main(void)
{
	char *quit="quit";
	char *string;
	while(1)
	{
		printf("Input string >>> ");
		scanf("%s",string);
		if(!memcmp(string,quit,4))
			break;
		printf("%s\n",string);
	}
}
