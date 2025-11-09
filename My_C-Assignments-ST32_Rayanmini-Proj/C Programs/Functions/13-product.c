#include<stdio.h>
int product(int,int);
int main()
{
	int p,n1,n2;
	printf("enter 2 numbers: ");
	scanf("%d%d",&n1,&n2);
	p=product(n1,n2);
	printf("%d\n",p);


}
int product(int n1,int n2)
{
	int p=0,i;
	for(i=1;i<=n2;i++)
	{
		p=p+n1;
	}
	return p;
}





