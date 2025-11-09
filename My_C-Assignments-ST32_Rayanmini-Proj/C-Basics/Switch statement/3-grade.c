#include<stdio.h>
int main()
{
	int m1,m2,m3,m4,m5,m6,per;
	printf("Enter marks of 6 subjects :\n");
	scanf("%d%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5,&m6);
	per=(m1+m2+m3+m4+m5+m6)/6;
	switch(per/10)
	{
		
		case 8:
			printf("Honours\n");
		    	break;					
		case 6:
			printf("First division\n");
			break;
		case 5:
			printf("Second division\n");
			break;
		case 4:
			printf("Third division\n");
			break;
		default:
			printf("fail\n");
	}
				return 0;
}

			 
		
