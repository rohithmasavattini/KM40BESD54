#include<stdio.h>
int main()
{
	int n,count=0;
	printf("Enter a number :\n");
	scanf("%d",&n);
	 if(n==0)
                printf("number of digits: %d\n",++count);
	 else
	{
	while(n!=0)
	{	
		n/=10;
		++count;
	}

	printf("number of digits: %d\n",count);
	
	}
}

