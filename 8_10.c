#include <stdio.h>
#include <string.h>
void main()
{
	char *str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr;
	ptr=strchr(str,'k');
	printf("%s\n",ptr);
}
