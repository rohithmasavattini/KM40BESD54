#include<stdio.h>
int main()
{
	int a,b;
	char op;
	printf("Enter number operator and another number :\n");
	scanf("%d%c%d",&a,&op,&b);
	switch(op)
	{
		case '+':
		       	printf("Result =%d\n",a+b);
			break;
		case '-':
			printf("Result =%d\n",a-b);
			break;
		case '*':
			printf("Result =%d\n",a*b);
			break;
		case '/':
			printf("Result =%d\n",a/b);
			break;
		case '%':
			printf("Result =%d\n",a%b);
			break;
		default:
			printf("Enter valid operator\n");
	}
	return 0;
}



