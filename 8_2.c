#include <stdio.h>
#include <ctype.h>
void main()
{
	int ch;
	while((ch=getchar())!=EOF)
	{
		if(isalpha(ch))
		{
			putchar(ch);
		}
	}
	putchar('\n');
}
