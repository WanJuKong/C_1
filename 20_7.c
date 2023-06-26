#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void output_file(FILE *fp);
int flag=0;
void main(int argc, char *argv[])
{
	FILE *fp;
	int opt;
	if(argc==1)
	{
		printf("Usage: ./20_7 [-n] [file name]\n");
		exit(1);
	}
	while((opt=getopt(argc,argv,"n"))!=-1)
	{
		switch(opt)
		{
			case 'n':
				flag=1;
				break;
			default:
				("unknown option: %c\n", optopt);
		}
	}
	if(flag==1)
		argv++;
	while (*++argv)
	{
		printf("\n[file name: %s]\n\n",*argv);
		if((fp=fopen(*argv,"r"))==NULL)
		{
			perror("fopen failed");
			exit(2);
		}
		output_file(fp);
		fclose(fp);
	}
	exit(0);
}

void output_file(FILE *fp)
{
	int ch,line=1;
	if(!flag)
		printf("1   ");
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		if(ch=='\n')
			printf("%-4d",++line);
	}
}
