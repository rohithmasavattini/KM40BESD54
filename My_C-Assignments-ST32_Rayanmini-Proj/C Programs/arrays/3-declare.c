#include<stdio.h>
int main()
{
	int arr[100],n;
	printf("enter size of array:");
	scanf("%d",&n);
	int i,small,large;
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	large=small=arr[0];
	for(i=1;i<n;i++)
	{
	if(arr[i]>large)
		large=arr[i];
	if(arr[i]<small)
		small=arr[i];
	}
	printf("small = %d\n",small);
	printf("large = %d\n",large);
	
	return 0;
}
			

