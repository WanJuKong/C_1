#include <stdio.h>
void printbit(char ch);
void main (){
	char a,b,c;
	int select;

	while(1){
		printf("\nselect menu:\n1. AND\n2. OR\n3. XOR\n4. EXIT\n>>> ");
		scanf("%d",&select);
		if(select==1){
			printf("input two characters>>>");
			scanf("\n%c %c",&a,&b);
			c=a&b;
			printbit(a);
			printf("AND");
			printbit(b);
			printf("=");
			printbit(c);
		}
		else if(select==2){
			printf("input two characters>>>");
			scanf("\n%c %c", &a,&b);
			c=a|b;
			printbit(a);
			printf("OR");
			printbit(b);
			printf("=");
			printbit(c);
		}
		else if(select==3){
			printf("input two characters>>>");
			scanf("\n%c %c",&a,&b);
			c=a^b;
			printbit(a);
			printf("XOR");
			printbit(b);
			printf("=");
			printbit(c);
		}
		else if(select==4){
			break;
		}
		else{
			printf("select erorr\n");
		}
	}
}

void printbit(char ch){
	int i;
	for(i=0;i<8;i++){
		printf("%d",(ch&128)?1:0);
		ch=ch<<1;
	}
}



			
