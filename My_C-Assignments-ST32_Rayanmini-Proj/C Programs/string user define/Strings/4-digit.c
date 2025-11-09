#include<stdio.h>
int main()
{
	int i=0,j,n,d;
	char *str[100];
	printf("enter integer value:");
	scanf("%d",&n);
	while(n>0)
	{
		d=n%10;
		n=n/10;
		switch(d)
		{
 		case 0: str[i]="zero";
			i++;
		      	break;
		case 1:str[i++]="one";
	       		break;
        	case 2:str[i++]="two";
        	       	break;
		case 3:str[i++]="three";
        	       	break;
		case 4:str[i++]="four";
        	       	break;
		case 5:str[i++]="five";
        	       break;
		case 6:str[i++]="six";
        	       break;
		case 7:str[i++]="seven";
        	       break;
		case 8:str[i++]="eight";
        	       break;
		case 9:str[i++]="nine";
        	       break;
		}
	}
		
		for(j=i-1;j>=0;j--)
		{
			printf("%s ",str[j]);
	
		}
		printf("\n");
		return 0;
}

