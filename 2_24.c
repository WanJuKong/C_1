#include <stdio.h>
func(int,int);
main(){
	int a,b;
	scanf("%d+%d", &a,&b);
	func(a,b);
}
func(int a, int b){
	printf("%d",a+b);
}
