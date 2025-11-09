#include<stdio.h>
void countbitset(int,int,int);
int main()
{
        int temp,size;
        char x=4;
        temp=sizeof(x);
        if(temp==1)
                size=0x80;
        else
                if(temp==4)
                        size=0x80000000;
        countbitset(x,size,temp);
        return 0;
}
void countbitset(int x,int size,int temp)
{
        int i,count=0;
        for(i=0;i<temp*8;i++)
	{
                if(x&size)
                        count++;
                x=x<<1;
        }
        printf("bit set count:%d\n",count);
}


