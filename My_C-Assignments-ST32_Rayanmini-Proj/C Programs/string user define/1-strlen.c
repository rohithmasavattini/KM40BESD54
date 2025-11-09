#include<stdio.h>
//#include<string.h>
int strlength(char str[]);
int main()
{
	char str[100];
	printf("enter string:");
	scanf("%s",str);
	printf("lenth of string: %u\n",strlength(str));
	return 0;
}
int strlength(char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
	i++;
	}	
	return i;	

}
