#include<stdio.h>
void addstock();
void deletestock();

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

