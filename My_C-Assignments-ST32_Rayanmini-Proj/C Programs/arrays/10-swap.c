#include<stdio.h>
int main()
{
	int i,n,a[100],temp;
	int b[100];
	printf("enter size array: ");
	scanf("%d",&n);
	printf("array 1:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array 2: ");
	for(i=0;i<n;i++)
	{

		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]=a[i]+b[i];
		b[i]=a[i]-b[i];
		a[i]=a[i]-b[i];
	/*	temp=a[i];
		a[i]=b[i];
		b[i]=temp; */
	}
	printf("array 1:");
	for(i=n-1;i>=0;i--)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
	printf("array 2:");
	for(i=n-1;i>=0;i--)
	{
		printf(" %d",b[i]);
	}
	printf("\n");
}
