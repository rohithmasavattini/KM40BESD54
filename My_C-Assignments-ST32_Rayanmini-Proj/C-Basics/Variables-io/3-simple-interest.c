#include<stdio.h>
int main()
{	
int p,n;
float r,m,si;
printf("Enter principle: ");
scanf("%d",&p);
printf("Enter time in months: ");
scanf("%d",&n);
printf("Enter rate of interest: ");
scanf("%f",&r);
m = n / 12;
si = p*r*m/100;
printf("simple interest: %f\n",si);

return 0;

}
