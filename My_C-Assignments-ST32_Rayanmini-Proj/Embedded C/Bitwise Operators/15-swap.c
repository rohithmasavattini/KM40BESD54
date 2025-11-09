#include<stdio.h>
int main()
{
	int x,y;
	printf("enter x and y values:");
	scanf("%d%d",&x,&y);
	printf("Before swaping:x=%d,y=%d\n",x,y);
	x=x^y;
	y=x^y;
	x=x^y;
	printf("After swapping:x=%d,y=%d\n",x,y);
}

