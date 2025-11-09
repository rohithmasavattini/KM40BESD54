#include<stdio.h>
#define PRIME(num,i,c) (num%i==0)? c++:c

int main()
{
	int n,i,c=0;
	printf("enter a number:");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	PRIME(n,i,c);
	
	if(c==1)
		printf("PRIME\n");
	else
		printf("Not\n");
	
}
