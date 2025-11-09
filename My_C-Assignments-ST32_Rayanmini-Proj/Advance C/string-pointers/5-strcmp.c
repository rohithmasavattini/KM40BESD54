#include<stdio.h>
int my_stringcmp(char *str1,char *str2);
int main()
{
	char str1[20],str2[20];
	printf("enter 2 strings: ");
	scanf("%s",str1);
	scanf("%s",str2);
	if(my_stringcmp(str1,str2)==0)
		printf("strings are same\n");
	else
		printf("strings are not same\n");
	return 0;
}

int my_stringcmp(char *str1,char *str2)
{
	int i=0;
	while(*str1!='\0' || *str2!='\0')
	{
		if(*str1!=*str2)
			return (*str1-*str2);
		str1++;
		str2++;
	}
	return 0;
}
