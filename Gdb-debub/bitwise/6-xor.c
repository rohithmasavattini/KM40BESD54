#include<stdio.h>
int xor(int a,int b);
int main()
{
        int a,b;
        printf("eneter two integers:");
        scanf("%d%d",&a,&b);
        printf("addition is: %d\n",xor(a,b));
}
int xor(int x,int y)
{
        return ((~x)&(y)) | ((x)&(~y));
}
