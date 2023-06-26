#include <stdio.h>
#include <string.h>
void main()
{
	char *str="ABCABCABCABCAGH";
	char *ptr;
	ptr=strrchr(str,'A');
	printf("%s\n",ptr);
}
