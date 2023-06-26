#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	char *value, *string;
	if(argc==1||argc>3)
	{
		exit(1);
	}
	if((value=getenv(argv[1]))!=NULL)
		printf("%s: %s\n",argv[1],value);
	else
		printf("%s: no value\n",argv[1]);
	if(argc==3)
	{
		string=(char *)malloc(strlen(argv[1])+strlen(argv[2])+2);
		strcpy(string, argv[1]);
		strcat(string,"=");
		strcat(string,argv[2]);
		putenv(string);
		if((value=getenv(argv[1]))!=NULL)
			printf("%s's new value : %s\n",argv[1],value);
		else
			printf("error: %s\n",string);
	}
	exit(0);
}
