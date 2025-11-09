#include<stdio.h>
int *fun(int *,int);
int main()
{
	int a[5]={1,2,3,4,5},i;
	static int *s;
	for(i=0;i<5;i++)
	{
	s=fun(a,i);
	printf("%d\n",*s);
	}
	return 0;
		
}

int *fun(int *arr,int i)
{
	static int sum;
	int *p=&sum;
	sum =arr[i]*arr[i];
	return p;

}
	

