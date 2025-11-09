#include<stdio.h>
int sumofarray(int arr[],int n);
int main()
{
	int arr[100];
	int sum,i,n;
	printf("enter array size:");
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);		
	}
	sum = sumofarray(arr,n);
	printf("%d\n",sum);
}


int sumofarray(int arr[], int n)			
{
	int sum=0,i;
	for(i=0;i<n;i++)
	{
		sum +=arr[i];
	}
		return sum;
}


