#include <stdio.h>
#include <ctype.h>
void main()
{
	int ch;
	while((ch=getchar())!=EOF)
	{
		if(islower(ch))
			ch=toupper(ch);
		else if(isupper(ch))
			ch=tolower(ch);
		putchar(ch);
	}
	putchar('\n');
}
