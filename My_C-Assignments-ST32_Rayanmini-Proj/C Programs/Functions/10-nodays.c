#include<stdio.h>
void daysinmonth(int,int);
void daysinyear(int);
int main()
{
	int m,y;
	printf("enter month and year: ");
	scanf("%d%d",&m,&y);
	daysinmonth(m,y);
   	daysinyear(y);
 	return 0;	
	
}
void daysinmonth(int m,int y)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		printf("days in month 31\n");
	else if(m==4||m==6||m==9||m==11)
		printf("days in month 30\n");
	else if((m=2) && ((y%400==0 || y%4==0 && y%100!=0)))
		printf("days in month 29\n");
	else
		printf("days in month 28\n");
}

void daysinyear(int y)
{
if(y%400==0 || y%4==0 && y%100!=0)
printf("number of days in year 366\n");
else
	printf("number of days in year 365\n");
}

