#include<stdio.h>
int *fun();
int *funs(int *,int i);
int main()
{
	int *p;
	p=fun();
	printf("%d\n",*p);
	p=fun();
	printf("%d\n",*p);

	int arr[3]={1,2,3},i;
 	static int s;
	int *p1=arr;
	for(i=0;i<3;i++)
	{
		p1=funs(arr,i);
		printf("%d\n",s);
		
	}
	
}
int *fun()
{
	static int s=1;
	s++;
	int *p=&s; 
	return p; //return &s;

}
	
int *funs(int *arr,int i)
{
	static int sum;
	sum=arr[i]*arr[i];
	printf("%d\n",sum);
	return &sum;
}


