#include <stdio.h>
void main()
{
	int ch, numalph=0;
	while((ch=getchar())!=EOF)
	{
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
		{
			numalph++;
		}
	}
	printf("alphabet : %d\n",numalph);
}
