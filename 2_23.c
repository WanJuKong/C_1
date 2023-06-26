#include <stdio.h>
int func();
main(){
	int i;
	i=func();
	printf("%d",i);
}

int func(){return 3;}
