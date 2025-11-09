#include<stdio.h>
int main()
{
int n,i,count=1;
printf("Enter n value :");
scanf("%d",&n);
for(i=2;i<n;i++)
{
        if(n%i == 0)
	{
		count=0;
                break;
        }
}
if(n==1)
{
	printf("1 is neither prime nor composite\n");
}
	else
	{
if(count)
	printf("Prime number\n");
	else
	printf("Not prime number\n");
										}

}


