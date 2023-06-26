#include <stdio.h>
main()
{
	int ch;
	while((ch=getchar())!=EOF)
	{
		if(ch=="\n"){
			break;
		}
		putchar(ch);
	}
	putchar("\n");
}
