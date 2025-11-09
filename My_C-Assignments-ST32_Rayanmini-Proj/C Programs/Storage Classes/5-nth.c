#include<stdio.h>
void nthtime(int);
void printsubscript(int);
void hello(int);


int main()
{
	int i,n;
	printf("enter n value :");
        scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		hello(i);
	}
}

void hello(int i)
{
	printf("i am called %d",i);
	printsubscript(i);
}


void printsubscript(int i)
{

	if(i>=11 && i<=13)
		printf("th ");
	else if(i%10==1)
                printf("st ");
        else if(i%10==2)
                printf("nd ");
        else if(i%10==3)
                printf("rd ");
  	// else if(i%10==4 || i%10==5 || i%10==6 || i%10==7 || i%10==8 || i%10==9 || i%10==0)
  	
	else if(i%10>=4 && i%10<=9 || i%10==0)
	{
		printf("th ");
	}
	printf("time\n");
}
    
	



