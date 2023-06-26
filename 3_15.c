#include <stdio.h>
void main(){
	int ch;
	printf("input character >>>");
	ch=getchar();
	if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))){
		printf("alphabet");
	}
	else if((ch>='0')&&(ch<='9')){
		printf("number");
	}
	else{
		printf("other");
	}
}

