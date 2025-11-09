#include<stdio.h>
void addstock(int);
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

