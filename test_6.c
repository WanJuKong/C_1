#include <stdio.h>
void main(void)
{
	int i=1;
	if((++i)<2||i==1)
	{
		printf("Y");
	}else{
		printf("N");
	}
	printf("%d",i);
}

