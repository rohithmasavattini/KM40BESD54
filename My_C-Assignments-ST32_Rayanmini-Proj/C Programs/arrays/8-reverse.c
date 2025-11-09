#include<stdio.h>
int main()
{
        int i,j,temp,arr[20],n;
        printf("enter size of an array: ");
        scanf("%d",&n);
        printf("enter elements:\n");
        for(i=0;i<n; i++)
        {
                scanf("%d",&arr[i]);
        }
        for(i=0,j=n-1; i<j ;i++,j--)
        {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
        }
        printf("after reversing the array is: ");
        for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
}

