#include<stdio.h>
#define ARRAY(a,b)  a>b?a:b

int main()
{
        int a[2],i;
	printf("array elements 2:");
	for(i=0;i<2;i++)
	{
        scanf("%d",&a[i]);
	}
        printf("big=%d\n",ARRAY(a[0],a[1]));
        return 0;
}

