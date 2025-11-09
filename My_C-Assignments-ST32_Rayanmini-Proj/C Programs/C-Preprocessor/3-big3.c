#include<stdio.h>
#define BIG2(a,b) a>b?a:b
#define BIG3(a,b,c) BIG2(BIG2(a,b),c)
int main()
{
        int x,y,z;
	printf("enter 3 integers:");
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",BIG3(x,y,z));
        return 0;
}

