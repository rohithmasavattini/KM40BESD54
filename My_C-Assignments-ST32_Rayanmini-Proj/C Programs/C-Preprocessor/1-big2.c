#include<stdio.h>
#define BIG2(a,b) a>b?a:b
int main()
{
        int x,y;
	printf("enter 2 integers:");
        scanf("%d%d",&x,&y);
        printf("%d\n",BIG2(x,y));
        return 0;
}

