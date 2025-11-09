#include<stdio.h>
unsigned int littletobig(int x);
int main()
{
	int a;
	printf("enter a number to convert le to be: ");
	scanf("%x",&a);
	printf("BIG_ENDIAN = 0x%X\n",littletobig(a));
}
unsigned int littletobig(int x)
{
	return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}


