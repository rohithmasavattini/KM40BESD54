#include<stdio.h>
int cmpdate(int,int,int,int,int,int);
int main()
{
        int d,d1,m1,y1,d2,m2,y2;
        printf("enter first date: ");
        scanf("%d-%d-%d",&d1,&m1,&y1);
	printf("enter second date: ");
	scanf("%d-%d-%d",&d2,&m2,&y2);
        if(cmpdate(d1,m1,y1,d2,m2,y2))	
        printf("%d-%d-%d first date is older\n",d1,m1,y1);
	else
        printf("%d-%d-%d second date is older\n",d2,m2,y2);
        return 0;
}
int cmpdate(int d1,int m1,int y1,int d2,int m2,int y2)
{
	if(y1<y2)
     	        return 1;
	if(y1<y2)
		return 0;
	if(m1<m2)
		return 1;
	if(m1>m2)
		return 0;
	if(d1<d2)
		return 1;
	if(d1>d2)
		return 0;
	
}

