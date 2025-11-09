#include<stdio.h>
char casereverse(char);
int main()
{
	char ch;
	printf("Enter a character :");
	scanf("%c",&ch);
	if(casereverse(ch))
		printf("%c\n",ch-32);
	else 
		printf("%c\n",ch);
}
char casereverse(char ch)
{
	if(ch>=97 && ch<=122)
	return 1;
	else
	return 0;
}
