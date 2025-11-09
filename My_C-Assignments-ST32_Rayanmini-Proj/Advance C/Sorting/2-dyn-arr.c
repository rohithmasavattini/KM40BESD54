#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 5
int main()
{
        char * ptr[n];
        char *temp;
        int i,j;
	printf("enter %d names:\n",n);
	for(i=0;i<n;i++)
	{
		ptr[i]=(char*)malloc(10*sizeof(char));
		scanf("%s",ptr[i]);
	}
        printf("before sorting: ");
        for(i=0;i<n;i++)
        {
                printf("%s ",ptr[i]);
        }

        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
                if(strcmp(ptr[i],ptr[j])>0)
                {
			temp=ptr[i];
			ptr[i]=ptr[j];
                        ptr[j]=temp;
                }
        }
        printf("\nAfter sorting: ");
        for(i=0;i<n;i++)
        {
                printf("%s ",ptr[i]);
        }
        printf("\n");
        return 0;
}


