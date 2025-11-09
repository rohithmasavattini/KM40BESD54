#include<stdio.h>
int main()
{
int a,b,c;
printf("Enter three number : ");
scanf("%d%d%d",&a,&b,&c);

if(a>b)
{
	if(a>c)
		printf("a is big :%d\n",a);
	else
		printf("c is big :%d\n",c);
}
else
{
	if(b>c)
		printf("b is big :%d\n",b);
	else
		printf("c id big :%d\n",c);
}

return 0;
}
