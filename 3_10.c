#include <stdio.h>
void main(){
	int a;
	short s;
	long d;
	unsigned f;
	printf("int: %d %d\nshort: %d %d\nlong: %d %d\nunsigned: %d %d", sizeof(int), sizeof(a), sizeof(short), sizeof(s), sizeof(long), sizeof(d), sizeof(unsigned), sizeof(f));
}
