#include<stdio.h>
#include<stdlib.h>
int *sorting(int *,int *);
int main()
{
	int i,k,n1,n2;
	int arr1[10]={10,12,13,14,15,16},arr2[10]={9,12,15,19,20};

	/*printf("enter number of elements of arr 1: ");
        scanf("%d",&n1);
        printf("enter %d elements in sorted order:",n1);
        for(i=0;i<n1;i++)
        {
                scanf("%d",&arr1[i]);
        }
        printf("enter number of elements of arr2: ");
        scanf("%d",&n2);
        printf("enter %d elements of sorted order:",n2);
        for(i=0;i<n2;i++)
        {
                scanf("%d",&arr2[i]);
        }*/

	int *ptr=sorting(arr1,arr2);

	printf("sorting elements are:\n");
        for(k=0;k<10;k++)
        {
                printf("%d ",ptr[k]);
        }
        printf("\n");

}

int *sorting(int *arr1,int *arr2)
{
        int i=0,j=0,k=0,temp;
	int *arr3=(int*)calloc(20,sizeof(int));
	while(i<6 && j<5)
	{
		if(arr1[i] < arr2[j])
		{
			arr3[k++]=arr1[i++];
		}
		if(arr1[i] > arr2[j])
		{
			arr3[k++]=arr2[j++];
		}
		if(arr1[i] == arr2[j])
		//else	
		{
			arr3[k++]=arr2[i++];
			j++;
		}
		
	}
		while(i<6)
		{
			arr3[k++]=arr1[i++];
		}
		while(j<5)
		{
			arr3[k++]=arr2[j++];
		}

	return arr3;
}




