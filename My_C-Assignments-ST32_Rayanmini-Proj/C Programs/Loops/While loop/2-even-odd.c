#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	while(a<=b)
	{
		if(a%2==0)
		printf("Even =%d\n",a);
		else
		printf("Odd =%d\n",a);	
		a++;

	}
	return 0;
}
