#include<stdio.h>
int checkstock(int);
void sales();
void purchase();
int main()
{
	extern int stock;
	int n,i=1;
	char ch;
	while(i==1)
	{
	printf("please enter your choice:\n");
	printf("1.check Available stock:\n2.purchase new items:\n3.sell item:\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1: n=checkstock(stock);
			printf("available stock is:%d\n",n);
			break;
		case 2:purchase();
			break;
		case 3:sales();
			break;
		default:printf("option is not valid\n");
	}

	printf("do you want to continue y/n:\n");
	scanf(" %c",&ch);
	if(ch=='y')
		i=1;
	else
		i=0;
	}
	
}


