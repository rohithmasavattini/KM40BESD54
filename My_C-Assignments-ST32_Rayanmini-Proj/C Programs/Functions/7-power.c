#include<stdio.h>
int power(int,int);
int main()
{
	int a,n,s;
	printf("enter a and n values: ");
	scanf("%d%d",&a,&n);
	s=power(a,n);
	printf("a to the power of n= %d\n",s);
	return 0;
}
int power(int a,int n)
{
	int i,s=1;
	for(i=1;i<=n;i++)
	{
		s=s*a;
	}
	return s;
}
