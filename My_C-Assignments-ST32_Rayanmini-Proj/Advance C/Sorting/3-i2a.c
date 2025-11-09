#include<stdio.h>
char *my_itoa(int );
int main()
{
	int n;
	char *p;
	printf("enter integer value:\n");
	scanf("%d",&n);	
	p=my_itoa(n);
	printf("%s",p);
}

char *my_itoa(int n)
{
	int i,j;
	char arr[10],temp;
	char *ptr=arr;
	for(i=0;n>0;i++)
	{
		arr[i]=n%10+48;
		n=n/10;
	}
	i=i-1;
	for(j=0;j<i;j++,i--)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	arr[i+j+1]='\0';
	return ptr;
	
}







