#include<stdio.h>
int main()

{

float cp,sp,profit;
printf("Enter sell price of n(15) items :\n");
scanf("%f",&sp);
printf("Enter profit of n(15) items :\n");
scanf("%f",&profit);

cp = sp-profit;
printf("cost price of n(15) items is :%f\n",cp);

cp = (sp-profit)/15;
printf("cost price of 1 item is :%f\n",cp);

return 0;

}	
