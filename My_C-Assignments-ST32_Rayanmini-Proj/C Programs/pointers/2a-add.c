#include<stdio.h>
int main()
{
	int a=10,b=20;
	int *p1=&a,*p2=&b;

	printf("add:%d+%d=%d\n",a,b,*p1+*p2);
}
