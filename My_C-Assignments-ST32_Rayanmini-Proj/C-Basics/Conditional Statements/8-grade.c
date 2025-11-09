#include<stdio.h>
int main()
{
float m1,m2,m3,m4,m5,m6,per;
printf("Enter marks of 6 subjects :\n");
scanf("%f%f%f%f%f%f",&m1,&m2,&m3,&m4,&m5,&m6);
per = (m1+m2+m3+m4+m5+m6)/6;
if (per>=80)
	printf("percentage:%f\nGrade is:Honours\n",per);
	else if (per>=60)
         printf("percentage:%f\nGrade is:First Division\n",per);
	else if (per>=50)
         printf("percentage:%f\nGrade is:Second Division\n",per);
	else if (per>=40)
	printf("percentage:%f\nGrade is:Third Division\n",per);
        else if (per<=39)
     	printf("percentage:%f\nGrade is:Fail\n",per);

return 0;
}

