#include<stdio.h>
int isvaliddate(int,int,int);	
int datecompare(int,int,int,int,int,int);
void printdateinformat(int,int,int);
void printsubscript(int);

int main()
{
	int i,n,d,m,y,d1,m1,y1;
	i=1;
	printf("enter n candidates:\n");
	scanf("%d",&n);
	printf("date of birth of 1st candidate: ");
	scanf("%d-%d-%d",&d,&m,&y);
	while(i<n)
	{
	printf("date of birth of another candidate: ");
	scanf("%d-%d-%d",&d1,&m1,&y1);
	if(isvaliddate(d1,m1,y1)!=1)
	{
		printf("date is not valid\n");
		continue;
	}
	if(datecompare(d,m,y,d1,m1,y1)!=1)
	{
	d=d1;
	m=m1;
	y=y1;
	}
	i++;
	}
	printsubscript(d);
	printdateinformat(d,m,y);


}


