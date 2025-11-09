#include<stdio.h>
char *replacechar(char *str,char c1,char c2);
int main()
{
	char str[20],c1,c2,*p;
	printf("enter a string:");
	scanf("%s",str);
	printf("enter a character replace:");
	scanf(" %c",&c1);
	printf("enter character to replace with: ");
	scanf(" %c",&c2);
	p=replacechar(str,c1,c2);
	printf("after replace %c with %c: %s\n",c1,c2,p);
	return 0;
}

char *replacechar(char *str,char c1,char c2)
{
	char *p;
	p=str;
	while(*str)
	{
		if(*str==c1)
		{
			*str=c2;
		}
		str++;
	}
	return p;

}

