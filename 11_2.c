#include <stdio.h>
#define MAX 128
void main(void)
{
	char str[MAX];
	while(gets(str) != 0)
	{
		puts(str);
	}
}
