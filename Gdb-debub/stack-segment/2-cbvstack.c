#include <stdio.h>
void swap(int a,int b);
int main()
{
        int a,b;
        printf("enter a and b:");
        scanf("%d%d",&a,&b);
        swap(a,b);
        return 0;
}

void swap(int a,int b)
{
        int t;
        t=a;
        a=b;
        b=t;
        printf("after swaping:%d %d\n",a,b);
}

