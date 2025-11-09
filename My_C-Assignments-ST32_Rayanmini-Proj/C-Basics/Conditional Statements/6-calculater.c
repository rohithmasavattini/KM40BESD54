#include<stdio.h>
int main()
{
char op;
int n1,n2;
printf("Enter an operator :\n");
scanf("%c",&op);
printf("Enter two integers :\n");
scanf("%d%d",&n1,&n2);

if(op=='+')
	printf("result is :%d\n",n1+n2);
else if(op=='-')
        printf("result is :%d\n",n1-n2);
else if(op=='*')
        printf("result is :%d\n",n1*n2);
else if(op=='/')
        printf("result is :%d\n",n1/n2);
else if(op=='%')
        printf("result is :%d\n",n1%n2);
return 0;
}
