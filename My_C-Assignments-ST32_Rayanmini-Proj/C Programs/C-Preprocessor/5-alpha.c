#include<stdio.h>
#define ISLOWER(c) (c>=97&&c<=122)
#define ISUPPER(c) (c>=65&&c<=90)
#define ISALPHA(c) ISUPPER(c) || ISLOWER(c)
#define ISNUM(c) (c>=48 && c<=57)
#define ISALPHANUM(c) ISNUM(c) || ISALPHA(c)

int main()
{
	char ch;
	printf("enter a character: ");
	scanf("%c",&ch);
	if(ISALPHANUM(ch))
		printf("alphanumeric\n");
	else
		printf("NOT alphanumeric\n");
	return 0;
}


	
