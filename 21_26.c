#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void main(int a, char *s[])
{
	int fd, flag;
	struct
	{
		char name[15];
		char phone[15];
	} student;
	if((fd=open(s[1], O_RDWR| O_CREAT, 0644))==-1)
	{
		perror("open failed");
		exit(1);
	}
	if((flag=fcntl(fd,F_GETFL))==-1)
	{
		perror("fcntl failed");
		exit(1);
	}
	flag|=O_APPEND;
	if((fcntl(fd, F_SETFL, flag))==-1)
	{
		perror("fcntl failed");
		exit(1);
	}
	while(1)
	{
		printf("intput name >>> ");
		scanf("%s",student.name);
		if(!strcmp(student.name,"quit"))
			break;
		printf("input phone.num >>> ");
		scanf("%s",student.phone);
		write(fd,(char *)&student, sizeof(student));
	}
	close(fd);
	exit(0);
}

