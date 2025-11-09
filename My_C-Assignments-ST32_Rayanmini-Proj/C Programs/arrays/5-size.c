#include<stdio.h>
int main()
{
        int size,i;
	printf("enter size of an array:\n");
	scanf("%d",&size);
	float arr[20]={1.4,1.5};
	printf("enter elements\n");
        for(i=0;i<size;i++)
        {

		scanf("%f",&arr[i]);
	}
	for(i=0;i<size;i++)
	{
                printf("%f\t",arr[i]);
	}
        printf("\n");
	return 0;
}
