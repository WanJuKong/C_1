#include <stdio.h>
void main()
{
	union position 
	{
		int class;
		char department[10];
	}my;
	int chk;
	printf("Highschool: 1\nuniversity: 2\nselect an option >>> ");
	scanf("%d",&chk);
	if(chk==1){
		printf("class >>> ");
		scanf("%d",&(my.class));
		printf("highschool: %d class\n", my.class);
	}
	else
	{
		printf("major >>> ");
		scanf("%s",my.department);
		printf("university: %s major\n",my.department);
	}
}
