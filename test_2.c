#include <stdio.h>
void main(){
	int ch,n1=0,n2=0;
	while((ch=getchar())!=EOF){
		if('A'<=ch<='Z'){
			n1++;
		}
		else if('a'<=ch<='z'){
			n2++;
		}
	}
	printf("\n%d %d\n", n1, n2);
}
