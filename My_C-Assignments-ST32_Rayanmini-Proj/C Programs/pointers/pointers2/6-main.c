#include<stdio.h>
#define size 2
int swap(int *);
int main()
{
	int arr[size]={1,2},i;
	int *p=arr;
	swap(p);
	//swap(arr);
	printf("After swaping: ");
	for(i=0;i<size;i++)
	{
	printf("%d ",arr[i]);	
	}
	printf("\n");
	return 0;
}


