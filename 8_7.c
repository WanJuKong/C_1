#include <stdio.h>
#include <string.h>
#define MAX 20
void main()
{
	char buffer1[MAX];
	char buffer2[MAX];
	strcpy(buffer1,"linux");
	printf("%s\n",buffer1);
	strcpy(buffer2,"programming");
	printf("%s\n",buffer2);
	strcpy(buffer2, buffer1);
	printf("%s\n",buffer2);
}
