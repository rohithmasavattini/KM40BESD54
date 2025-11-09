#include<stdio.h>
int main()
{
	int a,b,i;
	printf("enter dividend diviser: ");
	scanf("%d%d",&a,&b);
	
	for(i=0;a>=b;i++)
	{
		a=a-b;

	}
	printf("reminder: %d\n",a);
	printf("Quotient: %d\n",i);
}

