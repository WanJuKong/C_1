#include <stdio.h>
#include <string.h>
void main()
{
	char *ptr;
	ptr=strpbrk("seoulkorea","ka");
	printf("%s\n",ptr);
}
