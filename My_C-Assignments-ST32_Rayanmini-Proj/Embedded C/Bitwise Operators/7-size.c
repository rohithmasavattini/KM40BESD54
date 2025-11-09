#include<stdio.h>
void mysizeof(char x);
int main()
{
        char x=1;
	mysizeof(x);
}
void mysizeof(char x)
{
	int count=0;
	while(x!=0)
	{
		x=x<<1;
		count++;
	}
//	count=count/8;
	printf("size bits:%d\n",count);
}

      
