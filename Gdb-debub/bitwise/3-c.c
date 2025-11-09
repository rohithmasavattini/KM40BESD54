#include<stdio.h>
void displaybits(int);
int main()
{
        int x;
        printf("enter an integer:");
        scanf("%d",&x);
        displaybits(x);
        return 0;
}
void displaybits(int x)
{
        int i,mask,count=0;
       	for(i=31;i>=0;i--)
        {
                mask=1<<i;
                if(x&mask)
                count++;
        }
        printf("bits set count: %d\n",count);
}



