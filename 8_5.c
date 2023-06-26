#include <stdio.h>
#include <string.h>
void main()
{
	char buf1[20]="linux";
	char buf2[20]="linux";
	strcat(buf1," programming");
	strncat(buf2," programming",5);
	printf("%s\n%s\n",buf1,buf2);
}
