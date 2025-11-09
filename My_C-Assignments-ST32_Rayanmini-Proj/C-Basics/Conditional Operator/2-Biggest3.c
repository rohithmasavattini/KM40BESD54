#include<stdio.h>
int main()
{
int a,b,c,big;
printf("Enter three numbers :\n");
scanf("%d%d%d",&a,&b,&c);
big=(a>b)?((a>c)? a:c ) : ((b>c)? b:c);
printf("%d is big\n",big);

return 0;
}
