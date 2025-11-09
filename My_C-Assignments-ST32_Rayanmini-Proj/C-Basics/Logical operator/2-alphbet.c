#include<stdio.h>
int main()
{
char ch;
printf("Enter a character :\n");
scanf("%c",&ch);

if(ch>=68 && ch<=90 || ch>=97 && ch<=122)
	printf("%c is Alphabet\n",ch);
else
	printf("%c not Alphabet\n",ch);



return 0;
}
