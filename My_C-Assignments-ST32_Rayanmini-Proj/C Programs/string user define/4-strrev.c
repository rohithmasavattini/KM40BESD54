#include<stdio.h>
//#include<string.h>
void strreverse(char []);
int main()
{
	char str[50],temp;
	int i,j;
	printf("enter a string: ");
	scanf("%s",str);
	strreverse(str);
	printf("Reverse is: %s\n",str);
	return 0;
}

void strreverse(char str[])
{
	int i,j,temp;
//	j=strlen(str)-1;
	for(j=0;str[j]!=0;j++);
	j=j-1;
	for(i=0;i<j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;

	}
}



