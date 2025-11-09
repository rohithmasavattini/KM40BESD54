#include<stdio.h>
int main()
{
	int i,n,a,sum=0;
	printf("enter n numbers :");
	scanf("%d",&n);
	i=1;
	while(i<=n)
	{
		scanf("%d",&a);
		sum = sum+a;
		i++;
	}
	printf("sum =%d\n",sum);
	return 0;
}

