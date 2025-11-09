#include<stdio.h>
int main()
{
	int i,n,f=1;
	printf("enter factorial number\n");
	scanf("%d",&n);
	i=n;
	while(i>=1)
	{
		f=f*i;
		i--;
	}
	printf("%d\n",f);
}
