#include<stdio.h>
int main()

{

float l,w,area,peri;

printf("Enter lenth and width of a rectangular:\n");
scanf("%f%f",&l,&w);
area = l*w;
peri = 2*(l+w);
printf("Area of a rectangular is :%f\n",area);
printf("Perimeter of a rectangular is :%f\n",peri);

return 0;



}

