#include<stdio.h>
int main()
{
	int mask=0x01,n;
	printf("enter a number:");
	scanf("%d",&n);
	if((n & mask)==0)
		printf("EVEN\n");
	else
		printf("ODD\n");
	return 0;
}
