#include<stdio.h>
#include<string.h>
#define n 5
int main()
{
        char arr[n][20],temp[20];
        int i,j;
        printf("enter %d strings:\n",n);
        for(i=0;i<n;i++)
        {
                scanf("%s",arr[i]);
        }

        for(i=0;i<n;i++)
	{
           for(j=i+1;j<n;j++)
                if(strcmp(arr[i],arr[j]) > 0)
		{
                 	strcpy(temp,arr[i]);
			strcpy(arr[i],arr[j]);
			strcpy(arr[j],temp);
		}
	}
	printf("After sorting:\n");
        for(i=0;i<n;i++)
        {
                printf("%s ",arr[i]);
        }
	return 0;
}


