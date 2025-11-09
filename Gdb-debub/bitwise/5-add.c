#include<stdio.h>
int sum(int a,int b);
int main()
{
        int a,b;
        printf("eneter two integers:");
        scanf("%d%d",&a,&b);
        printf("addition is: %d\n",sum(a,b));
}
int sum(int x,int y)
{
        int i,carry;
	while(y!=0)
	{
		carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
