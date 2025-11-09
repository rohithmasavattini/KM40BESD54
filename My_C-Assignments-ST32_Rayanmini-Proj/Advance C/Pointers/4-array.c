#include<stdio.h>
int main()
{
        int a[10]={1,2,3,4,5,6,7,8,9,10},i;
        int *p;
	for(i=0;i<10;i++)
	{
		p=&a[i];
		printf("%p  %d\n",p,*p);
		//printf("%p  %d\n",&a[i],a[i]);
	
	}
	return 0;
}
        
