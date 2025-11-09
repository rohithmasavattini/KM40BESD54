#include<stdio.h>
void binary(int,int,int);
int main()
{
	int temp,size;
	char x=5;
	temp=sizeof(x);
	if(temp==1)
		size=0x80;
	else
		if(temp==4)
			size=0x80000000;
	binary(x,size,temp);
	return 0;
}
void binary(int x,int size,int temp)
{
	int i;
	for(i=0;i<temp*8;i++)
	{
		if(x&size)
			printf("1");
		else
			printf("0");
		x=x<<1;

	}
	printf("\n");
}

