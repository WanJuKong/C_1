#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int a, char *s[])
{
	int opt;
	while((opt=getopt(a,s,"lf:ai"))!=-1)
	{
		switch(opt)
		{
			case '1':
			case 'a':
			case 'i':
				printf("option: %c\n",opt);
				break;
			case 'f':
				printf("option %c's argument: %s\n",opt,optarg);
				break;
			defult:
				printf("UNKNOWN OPTION: %c\n",optopt);
		}
	}
	exit(0);
}
