#include<stdio.h>
int main()
{
	int i,j,n,temp;
	int a[100];
	printf("enter number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element %d :",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
	        int sort=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				sort++;
			}
		}
		if(sort=0)
		break;	
	}
	printf("sorting elements is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}



	

