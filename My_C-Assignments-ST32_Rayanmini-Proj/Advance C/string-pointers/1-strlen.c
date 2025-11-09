#include<stdio.h>
//#include<string.h>
int strlength(char *str);
int main()
{
	char str[100];
	printf("enter string:");
	scanf("%s",str);
	int l=strlength(str);
	printf("lenth of string: %u\n",l);
	return 0;
}
int strlength(char *str)
{
	int i=0;
	while(*str)
	{
	i++;
	str++;
	}	
	return i;	

}
