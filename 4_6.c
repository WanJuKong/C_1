#include <stdio.h>
void main()
{
	char *str;
	str="Hello";
	for(;*str;str++)
	{
		printf("%s\n",str);
	}
}
