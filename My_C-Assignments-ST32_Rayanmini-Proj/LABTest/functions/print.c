#include<stdio.h>

void printsubscript(int d)
{
	printf(" %d",d);
	if(d==1 || d==21 || d==31)
		printf("st ");
	else if(d>=4 && d<=20 || d>=24 && d<=30)
		printf("th ");
	else if(d=2 || d==22)
		printf("nd ");
	else
		printf("rd ");

}

void printdateinformat(int d,int m,int y)
{
	switch(m)
	{	
	case 1:
		printf("January-%d is elder of all\n",y);
		break;
	case 2:
                printf("February-%d is elder of all\n",y);
		break;
	case 3:
                printf("March-%d is elder of all\n",y);
		break;
	case 4:
                printf("April-%d is elder of all\n",y);
		break;
	case 5:
                printf("May-%d is elder of all\n",y);
		break;
	case 6:
                printf("June-%d is elder of all\n",y);
		break;
	case 7:
                printf("July-%d is elder of all\n",y);
		break;
	case 8:
                printf("August-%d is elder of all\n",y);
		break;
	case 9:
                printf("September-%d is elder of all\n",y);
		break;
	case 10:
                printf("October-%d is elder of all\n",y);
		break;
	case 11:
                printf("November-%d is elder of all\n",y);
		break;
	case 12:
                printf("December-%d is elder of all\n",y);
		break;
	}
}
