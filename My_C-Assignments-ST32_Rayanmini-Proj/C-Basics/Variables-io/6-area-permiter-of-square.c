#include<stdio.h>
int main()
{
float l,w,area,peri;
printf("enter length and width of a square:\n");
scanf("%f%f",&l,&w);
area = l*w;
peri = 2*(l+w);

printf("Area of a square is :%f\n",area);
printf("perimeter of a square is :%f\n",peri);

return 0;


}	
