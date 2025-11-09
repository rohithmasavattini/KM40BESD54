#include<stdio.h>
int isprime(int,int);
int main()
{
	int i,n,count;
	printf("enter n value:\n");
	scanf("%d",&n);
	count=isprime(n,i);
	if(count==1)
		printf("prime\n");
	else
		printf("Not prime\n");
}

int isprime(int n,int i)
{
	int count=0;
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
			count++;
	}
	if(count==1)
		return 1;
		else
			return 0;
	
	
}

