#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number:\n");
	scanf("%d",&n);
	switch(n%2)
	{
		case 0:
			printf("Number is even\n");
			break;
		default:
			printf("Number is odd\n");
	}
	return 0;
}
