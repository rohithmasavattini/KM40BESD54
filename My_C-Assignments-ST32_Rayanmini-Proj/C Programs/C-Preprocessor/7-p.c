#include<stdio.h>
#define PRIME(num1,num2,i,c) (num1%i==0)? c++:c

int main()
{
        int n1,n2,i,c;
        printf("enter 2 number:");
        scanf("%d%d",&n1,&n2);
	printf("PRIME NUMBERS:");
	while(n1<n2)
	{
		c=0;
        for(i=2;i<=n1;i++)
	{
        PRIME(n1,n2,i,c);
	}
        if(c==1)
                printf("%d ",n1);
	n1++;
	}	
	printf("\n");
}

