#include<stdio.h>
int main()
{
	int a=1,b=2,c=3;
	int *p;
	p=&a;
	p=&b;
        p=&c;
	printf("%d,%d,%d\n",*p,*p,*p);
	return 0;
}
