#include <stdio.h>

void main()
{
	int ch;
	while((ch=getchar())!=EOF)
	{
		if(ch>='a'&&ch<='z')
		{
			ch=ch-'a'+'A';
		}
		putchar(ch);
	}
	putchar('\n');
}
