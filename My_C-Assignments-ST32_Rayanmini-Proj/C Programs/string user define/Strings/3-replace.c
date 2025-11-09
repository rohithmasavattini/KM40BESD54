#include<stdio.h>
#include<string.h>
void replacechar(char str[],char c1,char c2);
int main()
{
	char str[20],c1,c2;
	printf("enter a string:");
	scanf("%s",str);
	printf("enter a character replace:");
	scanf(" %c",&c1);
	printf("enter character to replace with: ");
	scanf(" %c",&c2);
	replacechar(str,c1,c2);
	printf("after replace %c with %c: %s\n",c1,c2,str);
	return 0;
}

void replacechar(char str[],char c1,char c2)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==c1)
		{
			str[i]=c2;
		}
	}
	
}

