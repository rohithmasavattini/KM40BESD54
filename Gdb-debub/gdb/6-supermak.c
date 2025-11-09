#include <stdio.h>
int checkstock(int);
void sales();
void purchase();
void addstock(int);
//void deletestock();
void deletestock(int);

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
	
int stock=100;
int checkstock(int stock)
{
	return stock;
}
void deletestock(int item)
{
	stock -= item;
}
void addstock(int item)
{
	stock += item;
}


void purchase()
{
	int item,limit=500;
	extern int stock;
	printf("enter number of item purchase :");
	scanf("%d",&item);
	if(item+stock<=limit)
	{
		addstock(item);
		printf("purchase items: %d\n",item);
	}
	else
    	printf("Sorry not enough space\n");
}


void sales()
{
	int item;
        extern int stock;
	printf("enter number of items sold :");
	scanf("%d",&item);
	if(item<=stock)
	{
		deletestock(item);
		printf("%d are sold\n",item);
	}
	else
		printf("Sorry not enough stock\n");
}

