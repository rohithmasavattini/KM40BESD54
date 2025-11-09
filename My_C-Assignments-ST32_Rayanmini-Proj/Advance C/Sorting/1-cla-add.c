#include<stdio.h>
#include<stdlib.h>
int my_atoi(char *argv[],int);
int main(int argc,char *argv[])
{
	int a,b,result;
	char op;
	printf("this function was called by \"%s\".\n",argv[0]);
	if(argc != 4)
	{
		printf("the command has no valid arguments.\n");
	}
	
		a=my_atoi(argv,1);
		b=my_atoi(argv,3);
		op=argv[2][0];
		switch(op)
		{
			case '+':
				result=a+b;
				break;
			case '-':
				result=a-b;
				break;
			case '*':	
				result=a*b;
				break;
		}
		if(op=='+' || op=='-' || op=='*')
		{
                     	printf("%d%c%d=%d\n",a,op,b,result);
		}
		else
		{	
			printf("invlid operator\n");
                      	//printf("argv[1]-argv[3]=%d\n",a-b);
                           
                }
		return 0;	
}

int my_atoi(char *argv[],int k)
{
	int i,j=0,d,sum=0;
	for(i=k;argv[i][j]!='\0';j++)
	{
		d=argv[i][j]-48;
		sum=(sum*10)+d;
	}
	return sum;
}
		

