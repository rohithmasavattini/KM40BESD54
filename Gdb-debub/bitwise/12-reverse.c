#include<stdio.h>
int main()
{
	int n=0,num=0,c=0,rev=0;
	printf("enter the number:");
	scanf("%d",&n);
		while(n>0)
		{
			rev=rev<<1;
			if(n&1==1)
			{
				rev=rev^1;
			}
			n=n>>1;
		}
	printf("reverse =%d\n",rev);
	return 0;
}
