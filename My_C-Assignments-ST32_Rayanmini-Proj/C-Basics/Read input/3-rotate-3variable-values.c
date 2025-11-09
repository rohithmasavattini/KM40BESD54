#include<stdio.h>
int main ()
{
int a,b,c,temp;
printf("Enter a,b&c values :\n");
scanf("%d%d%d",&a,&b,&c);

printf("Before rotate %d %d %d\n",a,b,c);

temp = a;
a = b;
b = c;
c = temp;

printf("After rotate %d %d %d\n",a,b,c);
return 0;

}

