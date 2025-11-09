#include<stdio.h>
void strupper(char str[]);
int main()
{
	char str[50];
	printf("enter a string: ");
	scanf("%s",str);
	strupper(str);
}

void strupper(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a' && str[i]<='z')
		str[i]=str[i]-32;
	}
		printf("upper case: %s",str);
	
}

