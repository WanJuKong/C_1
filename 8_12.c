#include <stdio.h>
#include <string.h>
void main()
{
	char *str="Hello Linux Programming";
	char *ptr;
	ptr=strstr(str,"Linux");
	printf("%s\n",ptr);
}
