#include <stdio.h>
void main()
{
	int ch='z';
	do{
		printf("%c",ch--);
	}
	while (ch>='a');
	printf("\n");
}
