#include<stdio.h>
void deletestock(int);
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

