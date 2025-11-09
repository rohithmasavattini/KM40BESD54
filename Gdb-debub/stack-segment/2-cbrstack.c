#include<stdio.h>
void swap(int *,int *);
int main()
{
        int a,b;
        printf("enter a and b:");
        scanf("%d%d",&a,&b);
        swap(&a,&b);
        printf("After swaping:%d %d\n",a,b);
        return 0;
}

void swap(int *p1,int *p2)
{
        int t;
        t=*p1;
        *p1=*p2;
        *p2=t;
}

