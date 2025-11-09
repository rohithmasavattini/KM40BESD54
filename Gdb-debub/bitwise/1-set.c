#include<stdio.h>
#define SET_BIT(x,p) (x |=(0x1<<p))
#define CLEAR_BIT(x,p) (x &=~(0x1<<p))
#define TOGGLE_BIT(x,p) (x ^=(0x1<<p))

int main()
{
	int p,x;
	printf("enter number and position:");
	scanf("%d%d",&x,&p);

	printf("After set: %d\n",SET_BIT(x,p));
	printf("After clear: %d\n",CLEAR_BIT(x,p));
	printf("After toggle: %d\n",TOGGLE_BIT(x,p));
	return 0;
}
