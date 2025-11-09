#include<stdio.h>
#include<string.h>
#define n 5
int main()
{
	char * ptr[n]={"ghs","jhs","sad","bin","doze"};
	char *temp;
	int i,j;
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
			
		


