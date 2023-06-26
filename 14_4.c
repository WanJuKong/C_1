#include <stdio.h>
#include <time.h>
#define size 128
void main(void)
{
	time_t time_now;
	struct tm *tm_local;
	char buf[size];
	time(&time_now);
	tm_local=localtime(&time_now);
	printf("%s",asctime(tm_local));
	strftime(buf,sizeof(buf),"%c",tm_local);
	printf("%s\n",buf);
}
