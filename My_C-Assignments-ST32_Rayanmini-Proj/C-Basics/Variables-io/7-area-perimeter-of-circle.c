#include<stdio.h>
int main()
{
float area,perimeter,radius;
printf("Enter radius:\n");
scanf("%f",&radius);

area = 3.14*radius*radius;
perimeter = 2*3.14*radius;

printf("Area of a circle :%f\n",area);
printf("Perimeter of a circle :%f\n",perimeter);
return 0;



}
