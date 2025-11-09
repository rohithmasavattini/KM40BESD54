#include<stdio.h>
int sub(int a,int b);
int main()
{
	int a,b,s;
	printf("eneter two integers:");
	scanf("%d%d",&a,&b);
	s=sub(a,b);
	printf("differnce is: %d\n",s);
}
int sub(int a,int b)
{
	int s;
	s=a+ ~b+1;
	return s;
}





