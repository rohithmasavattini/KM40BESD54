#include<stdio.h>
int main()
{
	int k,n=20;
	printf("enter the 32 bit number:");
	scanf("%d",&k);
	k=k>>n;
	if(k&1==1)
		printf("%d th bit is set\n",n);
	else
		printf("%d th bit is not set\n",n);
	return 0;
}

	
