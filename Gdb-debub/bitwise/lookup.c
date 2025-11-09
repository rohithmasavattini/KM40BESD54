#include<stdio.h>
int bitset(int n);
int main()
{
        int n;
        printf("enter an integer:");
        scanf("%d",&n);
       // bitset(n);
        printf("bits set count:%d\n",bitset(n));
        return 0;
}
int bitset(int n)
{
     unsigned int count=0;		
     char a[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
     //for(;n;n>>=4)
    count = a[n&0xf] + a[(n>>8) & 0xf] + a[(n>>16) & 0xf] + a[(n>>24) & 0xf];    

     count=count+ a[n & 0xF];
     return count;
}


