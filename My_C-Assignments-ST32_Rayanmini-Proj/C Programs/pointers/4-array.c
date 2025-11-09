#include<stdio.h>
int main()
{
        int a[5]={1,2,3,4,5},i;
        int *p;
	for(i=0;i<5;i++)
	{
	   p = &a[i];
	   printf("%p  %d\n",&a[i],*p);
		
	}
	return 0;
}
        
