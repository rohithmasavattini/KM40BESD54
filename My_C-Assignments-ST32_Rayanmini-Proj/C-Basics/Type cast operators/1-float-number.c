#include<stdio.h>
int main()
{
	float num;
	int ip;
	printf("Enter a floating point number :\n");
	scanf("%f",&num);
	ip = (int)num;
	 
	printf("right most of the intergal part= %d\n",ip%10);
	return 0;
}
