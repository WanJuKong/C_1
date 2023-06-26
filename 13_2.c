#include <stdio.h>
#include <search.h>
#include <string.h>

#define T_SIZE 10
#define D_SIZE 15

int compare(const void *a, const void *b);
void main(void)
{
	char table[T_SIZE][D_SIZE]={"Hello","Linux","c"};
	char *ptr;
	size_t datanum=3;
	if((ptr=(char *)lfind("Linux",table,&datanum,D_SIZE,compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n",ptr);
	if((ptr=(char *)lfind("Programming",table,&datanum,D_SIZE,compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n",ptr);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}
