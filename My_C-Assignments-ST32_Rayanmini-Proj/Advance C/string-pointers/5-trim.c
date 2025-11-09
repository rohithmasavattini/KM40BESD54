#include<stdio.h>
void trimleading(char *str);
int strlength(char *str);
int main()
{
	char str[100];
	printf("enter a string:");
	scanf("%[^\n]s",str);
	trimleading(str);
	printf("\"%s\"\n",str);

}
void trimleading(char *str)
{
	int a,b,l=strlength(str),i;
	for(i=0;i<l;i++)
	{
		if(*(str+i)!=' ')
		{
			a=i;
			break;
		}
	}
	for(i=l-1;i>=0;i--)
	{
		if(*(str+i)!=' ')
		{
			b=i;
			break;
		}
	}
	int j=0;
	for(i=a;i<=b;i++,j++)
	{

		*(str+j)=*(str+i);
	}
	*(str+j)='\0';

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
