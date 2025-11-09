#include<stdio.h>
int calc(int *p1,int *p2,int *p3,int *p4,int *p5,int a,int b);
int main()
{
        int a,b,x,p2,p3,p4,p5;
        printf("enter two integers:");
        scanf("%d%d",&a,&b);
        calc(&x,&p2,&p3,&p4,&p5,a,b);
        printf("add %d+%d is: %d\n",a,b,x);
        printf("sub %d-%d is: %d\n",a,b,p2);
        printf("mul %d*%d is: %d\n",a,b,p3);
        printf("div %d/%d is: %d\n",a,b,p4);
        printf("mod %d mod %d is: %d\n",a,b,p5);
}
int calc(int *p1,int *p2,int *p3,int *p4,int *p5,int a,int b)
{
        *p1=a+b;
        *p2=a-b;
        *p3=a*b;
        *p4=a/b;
        *p5=a%b;
	
}
