#include<stdio.h>
int add(int a, int b)
{
        return a+b;
}
int sub(int a, int b)
{
        return a-b;
}
int mul(int a, int b)
{
        return a*b;
}
int div(int a, int b)
{
        return a/b;
}
int mod(int a, int b)
{
	return a%b;
}

int main()
{
	int a,b;
	char op;
	printf("Enter a operator and b:\n");
	scanf("%d%c%d",&a,&op,&b);
	switch(op)
	{
		case '+':printf("%d+%d =%d\n",a,b,add(a,b));
			 break;
		case '-':printf("%d-%d =%d\n",a,b,sub(a,b));
			 break;
		case '*':printf("%d*%d =%d\n",a,b,mul(a,b));
			 break;
		case '/':printf("%d/%d =%d\n",a,b,div(a,b));
			 break;
		case '%':printf("%d mod %d =%d\n",a,b,mod(a,b));
			 break;
		default:printf("Not implimented\n");

	}
	return 0;
}

