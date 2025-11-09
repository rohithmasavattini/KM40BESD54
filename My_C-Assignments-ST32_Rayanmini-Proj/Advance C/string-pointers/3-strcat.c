#include<stdio.h>
char *my_stringcat(char *str1,char *str2);
int main()
{
	char str1[30]="kernel";
	char str2[30];
	printf("enter string2:");
	scanf("%s",str2);
	my_stringcat(str1,str2);
	printf("%s\n",str1);
}

char *my_stringcat(char *str1,char *str2)
{
	char *p;
	p=str1;
	while(*str1)
	{
		str1++;
	}	
	while(*str2)
	{
		*str1++=*str2++;
	}
	*str1='\0';
	return str1;
}	
