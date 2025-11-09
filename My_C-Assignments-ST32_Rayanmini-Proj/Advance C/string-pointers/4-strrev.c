#include<stdio.h>
char *my_strreverse(char *,char *);
int main()
{
	char str[50],revstr[100];
	printf("enter a string: ");
	scanf("%s",str);
	my_strreverse(str,revstr);
	printf("Reverse is: %s\n",revstr);
	return 0;
}
char *my_strreverse(char *str,char *strrev)
{
	char *rvptr=strrev;
	int i=0;
	while(*str)
	{
		str++;
		i++;
	}
	i=i-1;
	while(i>=0)
	{
		str--;
		*rvptr=*str;
		rvptr++;
		--i;
	}
	return rvptr;
}

