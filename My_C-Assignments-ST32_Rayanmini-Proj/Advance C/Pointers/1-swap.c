#include<stdio.h>
void swap_cbv(int a,int b);
void swap_cbr(int *p1,int *p2);
int main()
{
	int a,b;
	printf("enter a and b:");
	scanf("%d%d",&a,&b);
	swap_cbv(a,b);
	printf("After swaping_CBV Main:a=%d b=%d\n",a,b);
	swap_cbr(&a,&b);
	printf("After swaping_CBR:a=%d b=%d\n",a,b);
	return 0;
}

void swap_cbv(int a,int b)
{
        int t;
        t=a;
        a=b;
        b=t;
        printf("after swaping_CBV:a=%d b=%d\n",a,b);
}

void swap_cbr(int *p1,int *p2)
{
	int t;
	t=*p1;
	*p1=*p2;
	*p2=t;

}

