#include<stdio.h>
int main()
{
	int n;
	printf("enter an integer:");
	scanf("%d",&n);
	printf("%d*9= %d\n",n,((n<<3)+n));
	return 0;
}

