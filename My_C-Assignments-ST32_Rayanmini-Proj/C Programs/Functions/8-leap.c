#include<stdio.h>
int leap(int);
int main()
{
        int y,l;
        printf("enter year: ");
        scanf("%d",&y);
	if(leap(y))
        printf("leap year\n");
	else
		printf("not leap year\n");
        return 0;
}
int leap(int y)
{
	if((y%400 == 0)||(y%4==0 && y%100!=0))
        	return 1;

	return 0;
}

