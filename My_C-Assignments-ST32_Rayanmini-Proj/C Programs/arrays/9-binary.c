#include<stdio.h>
int main()
{
	int i,arr[100],n;
	printf("enter decimal number: ");
	scanf("%d",&n);
	for(i=0;n>0;i++)
	{
		arr[i]=n%2;
		n/=2;
	}
	for(i=i-1;i>=0;i--)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}
