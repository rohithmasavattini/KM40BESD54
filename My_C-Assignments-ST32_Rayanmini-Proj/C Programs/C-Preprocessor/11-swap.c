#include<stdio.h>
#define SWAP(dt,fn)\
	dt fn(dt x,dt y)\
{\
	dt t;   \
	t=x;  \
	x=y; 	\
	y=t;\
	printf("After swaping:a=%d b=%d\n",x,y);\
}


SWAP(int,swap_int)
//SWAP(float,swap_float)
int main()
{
	int a=10,b=20;
	float c=1.5,d=2.4; 
	printf("Before swaping:a=%d b=%d\n",a,b);
	swap_int(a,b);
//	swap_float(c,d);
	
}


