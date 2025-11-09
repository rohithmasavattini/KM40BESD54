#include<stdio.h>
int rotate(int *,int *,int *);
int main()
{
	int a,b,c;
	printf("enter a,b,c values:");
	scanf("%d%d%d",&a,&b,&c);
	rotate(&a,&b,&c);
	printf("after rotate: a=%d,b=%d,c=%d\n",a,b,c);
	return 0;
}
int rotate(int *p1,int *p2,int *p3)
{
	int temp;
	temp=*p1;
	*p1=*p3;
	*p3=*p2;
	*p2=temp;
}
