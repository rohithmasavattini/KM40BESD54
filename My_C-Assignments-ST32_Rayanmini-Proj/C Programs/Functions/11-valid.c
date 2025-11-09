#include<stdio.h>
int validdate(int,int,int);
int main()
{
        int d,m,y;
        printf("enter date month and year: ");
        scanf("%d-%d-%d",&d,&m,&y);
       if(validdate(d,m,y))
	       printf("Valid date\n");
       else
	       printf("invalid date\n");
        
        return 0;
}
int validdate(int d,int m,int y) 
{
	if(y>=1)
	{
		if(m>=1 && m<=12)
		{			
		     if((d>=1 && d<=31) && (m==1||m==3||m==5||m==7|m==8||m==10||m==12))
			return 1;
			if((d>=1 && d<=30) && (m==4||m==6||m==9||m==11))
			return 1;
			if((d>=1 && d<=28) && (m==2))
			return 1;
			if((d==29 && m==2) && (y%400==0 || (y%4==0 && y%100!=0)))
			return 1;	
			else
			return 0;
		}
	}
}
			
			

