#include<stdio.h>
int main()
{
float units,bill;
printf("Enter number of units :\n");
scanf("%f",&units);

if(units<=200)
	bill=100;
else if(units<=400)
	bill=100+(units-200)*0.65;
else if(units<=600)
        bill=230+(units-400)*0.80;
else if(units>=601)
        bill=390+(units-600)*1;
        printf("Bill :%f\n",bill);


return 0;
}
