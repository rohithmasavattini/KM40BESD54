#include <stdio.h>
int main()

{

int cash;

printf("Enter amount :\n");
scanf("%d",&cash);

printf("2000 :%d\n", cash/2000);
cash=cash%2000;

printf("500 :%d\n", cash/500);
cash=cash%500;

printf("200 :%d\n", cash/200);
cash=cash%200;

printf("100 :%d\n", cash/100);
cash=cash%100;

printf("50 :%d\n", cash/50);
cash=cash%50;

return 0;



}

