#include <stdio.h>
#include <string.h>
void main()
{
	char buf[20];
	int line=1;
	while(1)
	{
		printf("Input spring >>> ");
		scanf("%s",buf);
		if(!strcmp(buf,"quit"))
		{
			break;
		}
		printf("%1d:%s\n",line++,buf);
	}
}
