#include <stdio.h>
#include <search.h>
void main(void)
{
	ENTRY item;
	ENTRY *result;
	hcreate(5);
	item.key="L";
	item.data="Linux";
	hsearch(item,ENTER);
	item.key="C";
	item.data="C";
	hsearch(item,ENTER);
	item.key="P";
	item.data="Programming";
	hsearch(item,ENTER);
	item.key="L";
	item.data="Linux";
	if((result=hsearch(item,FIND))==NULL)
		printf("Not found\n");
	else
		printf("Found: %s\n",(char *)item.data);
	item.key="J";
	item.data="Java";
	if((result=hsearch(item,FIND))==NULL)
		printf("Not found\n");
	else
		printf("Found:%s\n",(char *)result -> data);
}
