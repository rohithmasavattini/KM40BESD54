#include<stdio.h>
#include"cal.h"
int main()
{
	
        int p,q,r,s,a,b;
	printf("enter a and b values:");
	scanf("%d%d",&a,&b);
        p=ADD(a,b);
        q=SUB(a,b);
        r=MUL(a,b);
     	s=DIV(a,b);
        printf("ADD=%d\nSUB=%d\nMUL=%d\nDIV=%d\n",p,q,r,s);
        return 0;
}

