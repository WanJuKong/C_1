#include <stdio.h>
#include <string.h>
void main(void)
{
	char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	memmove(alphabet,alphabet+7,19);
	printf("%s\n",alphabet);
}
