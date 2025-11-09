#include<stdio.h>
int main()

{

int n,d1,d2,d3,d4;
printf("Enter 4 digit number:\n");
scanf("%d",&n);

//op:1

d1=n%10;
n=n/10;
d2=n%10;
n=n/10;
d3=n%10;
n=n/10;
d4=n%10;
printf("%d\n%d\n%d\n%d\n",d1,d2,d3,d4);


//op:2


printf("Enter 4 digit number:\n");
scanf("%d",&n);

d1=n%10;
n=n/10;	
d2=n%10;
n=n/10;
d3=n%10;
n=n/10;
d4=n%10;
printf("%d\n%d\n%d\n%d\n",d4,d3,d2,d1);


//op:3

int n;
printf("%d\n",n/1000);
printf("%d\n",n/100);
printf("%d\n",n/10);
printf("%d\n",n);


//op:4

printf("\n%d\n",n);
printf("%d\n",n/10);
printf("%d\n",n/100);
printf("%d\n",n/1000);

return 0;


}	
