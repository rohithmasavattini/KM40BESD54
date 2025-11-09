#include<stdio.h>
int isvaliddate(int d1,int m1,int y1)
{
	if(y1>=1)
	{        
                if(m1>=1 && m1<=12)
		{
                     if((d1>=1 && d1<=31) && (m1==1||m1==3||m1==5||m1==7|m1==8||m1==10||m1==12))
                        return 1;
                        if((d1>=1 && d1<=30) && (m1==4||m1==6||m1==9||m1==11))
                        return 1;
                        if((d1>=1 && d1<=28) && (m1==2))
                        return 1;
                        if((d1==29 && m1==2) && (y1%400==0 || (y1%4==0 && y1%100!=0)))
                        return 1;
                        else
                        return 0;
                }
        }
}
