#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_SIZE 5
#define D_SIZE 10

int compare(const void *a, const void *b);
void main(void)
{
	char table[T_SIZE][D_SIZE]={"C","Html","Java","Perl","XML"};
	char *ptr;
	if((ptr=(char *)bsearch("Java",table,T_SIZE,D_SIZE,compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n",ptr);
	if((ptr=(char *)bsearch("Linux",table,T_SIZE,D_SIZE,compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n",ptr);
}

int compare(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
