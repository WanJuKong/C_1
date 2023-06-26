#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 5
#define DSIZE 15

int compare(const void *a, const void *b);
void main(void)
{
	int i;
	char table[TSIZE][DSIZE]={"Hello","Linux","C","Programming","Java"};
	qsort(table,TSIZE,DSIZE,compare);
	for(i=0;i<TSIZE;i++)
	{
		printf("%s\n",table[i]);
	}
}
int compare(const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}
