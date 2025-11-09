#include<stdio.h>
int search(int arr[],int n1);
int main()
{
	int arr[100];
	int i,n,n1,found,s;
	printf("Enter array size :");
	scanf("%d",&n);
	printf("enter array elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter search element: ");
	scanf("%d",&n1);
	s=search(arr,n1);
	printf("%d array index is: %d\n",n1,s);
	return 0;

}

int search(int arr[],int n1)
{
	int found=0,i,n,s;
	for(i=0;i<n;i++)
	{
		if(arr[i]==n1)
		{
			found=1;
			break;
		}

	}
	if(found==1)
		return s=i;

}
