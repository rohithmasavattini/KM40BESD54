#include<stdio.h>
char *my_strupper(char *str);
int main()
{
	char str[50];
	printf("enter a string: ");
	scanf("%s",str);
	my_strupper(str);
	printf("upper case string: %s\n",str);
	return 0;

}

char *my_strupper(char *str)
{
	char *p=str;
	while(*str)
	{
		if(*str>='a' && *str<='z')
		*str=*str-32;
		str++;
	}
	return p;
	
}

