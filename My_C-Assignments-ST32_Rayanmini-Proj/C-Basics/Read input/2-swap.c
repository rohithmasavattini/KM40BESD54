#include<stdio.h>
int main()

{

int a,b,temp;
printf("Enter two numbers:\n");
scanf("%d%d",&a,&b);
/*temp = a;
a = b;
b = temp;*/

a= a+b;
b=a-b;
a=a-b;
printf("After swaping: %d %d\n",a,b); 
return 0;

}
