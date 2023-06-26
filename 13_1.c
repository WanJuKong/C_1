#include <stdio.h>
#include <search.h>
#include <string.h>

#define T_SIZE 10
#define D_SIZE 15

int compare(const void *a, const void *b);
void main(void)
{
	char table[T_SIZE][D_SIZE]={"Hello","Linux","C"};
	char *ptr;
	size_t datanum=3;
	ptr=(char *)lsearch("Linux",table,&datanum,D_SIZE,compare);
	printf("%s\n",ptr);
	ptr=(char *)lsearch("Programming",table,&datanum,D_SIZE,compare);
	printf("%ld\n",datanum);
	printf("%s\n",ptr);
	printf("%s %d\n",__FUNCTION__,__LINE__);
}

int compare(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
