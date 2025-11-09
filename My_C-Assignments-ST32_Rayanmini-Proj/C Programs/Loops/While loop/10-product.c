#include<stdio.h>
int main()
{
	int i,n1,n2,j=0;
	printf("enter two numbers\n");
	scanf("%d%d",&n1,&n2);
	i=1;
	while(i<=n2)
	{
	
		j = j+n1;
		i++;
	}
	printf("%d\n",j);
}
