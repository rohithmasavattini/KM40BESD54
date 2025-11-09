#include<stdio.h>
void multable(int n,int i);
int main()
{
	int n,i;
	printf("enter n value:\n");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
	multable(n,i);
	}
	
}

void multable(int n,int i)
{
	printf("%d*%d = %d\n",n,i,n*i);
}
