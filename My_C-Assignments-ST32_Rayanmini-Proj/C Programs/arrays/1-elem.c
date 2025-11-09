#include<stdio.h>
int main()
{
        int arr[100]={0-100},i;
        for(i=0;i<100;i++)
	{
		arr[i]=i;
	}
		for(i=1;i<100;i++)
		{
  		printf("%d\t",arr[i]);
		}
	printf("\n");

	printf("even numbers :");
	for(i=1;i<100;i++)
	{

		if(arr[i]%2==0)
		printf("%d \t",arr[i]);	
	}
	printf("\n");
	
	printf("odd numbers\n");
	for(i=1;i<100;i++)
	{
		if(arr[i]%2!=0)
		printf("%d \t",arr[i]);
		
	}
	printf("\n");
	printf("adding 5 to elemenrs\n");
	for(i=1;i<100;i++)
	{
		arr[i]+= 5;
	printf("%d\t",arr[i]);
	}
        return 0;
}

