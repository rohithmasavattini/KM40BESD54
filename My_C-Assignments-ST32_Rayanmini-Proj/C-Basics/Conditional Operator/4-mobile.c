#include<stdio.h>
int main()
{
int call;
float bill;
printf("enter the number of calls :\n");
scanf("%d",&call);
call>100 ? printf("bill is %f\n",bill=250+(call-100)*1.25) : printf("bill is %f",bill=250);

return 0;
}
