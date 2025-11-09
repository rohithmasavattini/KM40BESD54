#include<stdio.h>
int main()
{
	int a,b,sum,s,m,d,r;
        printf("Enter two integer values:\n");
	scanf("%d%d",&a,&b);
	sum = a + b;
	s = a - b;
	m = a * b;
	d = a / b;
	r = a % b;
	printf("sum of %d and %d is:%d\n" ,a,b,sum);
	printf("subtraction of %d and %d is:%d\n" ,a,b,s);
	printf("multiplication of %d and %d is:%d\n" ,a,b,m);
	printf("division of %d and %d is:%d\n" ,a,b,d);
	printf("reminder of %d and %d is:%d\n" ,a,b,r);
	return 0;

}
