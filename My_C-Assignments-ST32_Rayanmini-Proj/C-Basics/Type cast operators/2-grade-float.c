#include<stdio.h>
int main()
{
        int m1,m2,m3,m4,m5,m6;
	float per;
        printf("Enter marks of 6 subjects :\n");
        scanf("%d%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5,&m6);
        per=(float)(m1+m2+m3+m4+m5+m6)/6;
	printf("Percentage = %.2f\n",per);
	return 0;

           
    

}     
