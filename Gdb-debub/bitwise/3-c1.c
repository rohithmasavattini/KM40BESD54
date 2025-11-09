#include<stdio.h>
int bitset(int n);
int main()
{
	int n;
	printf("enter an integer:");
	scanf("%d",&n);
	bitset(n);
	printf("bits set count:%d\n",bitset(n));
	return 0;
}
int bitset(int n)
{
	int count=0;
	while(n!=0)
	{
		n=n&(n-1);
		count++;
	}
	return count;
}

