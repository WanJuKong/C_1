#include <stdio.h>
void main(){
	int i;
	printf("input integer >>> ");
	scanf("%d",&i);
	switch (i){
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		default:
			printf("more than 2");
	}
}
