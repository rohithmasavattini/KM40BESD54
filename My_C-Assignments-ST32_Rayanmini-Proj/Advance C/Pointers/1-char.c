#include<stdio.h>
int main()
{
	char a,b;
	printf("enter a character:");
	scanf(" %c",&a);
	printf("enter another character:");
	scanf(" %c",&b);
	char *p1=&a;
	char *p2=&b;
	if(*p1>*p2)
		printf("character %c higher Ascii value: %d\n",a,*p1);
	if(*p1<*p2)
		 printf("character %c higher Ascii value: %d\n",b,*p2);
	if(*p1==*p2)
		printf("Both are same\n");

}

