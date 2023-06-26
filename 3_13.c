#include <stdio.h>
void main(){
	char ch;
	while((ch=getchar())!=EOF){
		printf("%c",((ch>='a')&&(ch<='z'))?ch-'a'+'A':ch);
	}
}
