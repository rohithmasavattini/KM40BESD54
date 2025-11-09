#include<stdio.h>
int main()
{
int date1,date2,month1,month2,year1,year2;
printf("Enter 2 dates day&month&year :\n");
scanf("%d-%d-%d",&date1,&month1,&year1);
scanf("%d-%d-%d",&date2,&month2,&year2);
if(year1<year2)
       printf("%d-%d-%d is older date\n",date1,month1,year1);
else if(month1<month2)
        printf("%d-%d-%d is older date\n",date1,month1,year1);
else if (date1<date2)
	printf("%d-%d-%d is older date\n",date1,month1,year1);
else
	printf("%d-%d-%d is older date\n",date2,month2,year2);


return 0;
}
