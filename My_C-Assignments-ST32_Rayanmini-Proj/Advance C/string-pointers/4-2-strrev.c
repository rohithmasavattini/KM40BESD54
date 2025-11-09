#include<stdio.h>
char *my_strreverse(char *);
int main()
{
	char str[50];
	printf("enter a string: ");
	scanf("%s",str);
	my_strreverse(str);
	printf("Reverse is: %s\n",str);
	return 0;
}
char *my_strreverse(char *str)
{
	char *p,temp;
	p=str;
	int i,j;
	for(i=0;*str!='\0';i++,str++);
	i=i-1;
	for(j=0;j<i;j++,i--)
	{  
		temp=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=temp;
	}
	return p;
}

