#include<stdio.h>
int main()
{
	volatile int x=10;
	printf("%d\n",++x * x++);
}
