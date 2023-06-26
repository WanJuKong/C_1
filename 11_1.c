#include <stdio.h>
#include <ctype.h>
void main(void)
{
	int ch;
	while((ch=getchar())!=EOF)
		putchar(tolower(ch));
}
