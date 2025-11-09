#include<stdio.h>
int main()
{
        int n,p;
        printf("enter the 32 bit number:");
        scanf("%d",&n);
	printf("enter which position:");
	scanf("%d",&p);
	if(n & (0x1<<p))
                printf("%d th bit is set\n",p);
        else
                printf("%d th bit is not set\n",p);
        return 0;
}

