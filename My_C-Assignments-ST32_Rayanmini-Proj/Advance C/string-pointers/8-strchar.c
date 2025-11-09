#include<stdio.h>
char *my_strchar(char *str,int c);
int main()
{
	char str[20],c;
	char *p;
	printf("enter a string:");
	scanf("%s",str);
	printf("enter a character:");
	scanf(" %c",&c);
	p=my_strchar(str,c);
	if(p==0)
		printf("not found\n");
	else
	printf("%s\n",p);
	return 0;
}
char *my_strchar(char *str,int c)
{
	while(*str)
	{
		if(*str == c)
		return str;
		str++;
	}
	return 0;
}
