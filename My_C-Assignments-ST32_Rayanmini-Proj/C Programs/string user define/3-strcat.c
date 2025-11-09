#include<stdio.h>
void stringcat(char str1[],char str2[]);
int main()
{
	char str1[30]="rohit";
	char str2[30];
	printf("enter string2: ");
	scanf("%s",str2);
	stringcat(str1,str2);
}

void stringcat(char str1[],char str2[])
{
	int i,j;
	for(i=0;str1[i]!='\0';i++);
	for(j=0;str2[j]!='\0';i++,j++)
	{
		str1[i]=str2[j];
	}
	str1[i]='\0';
	printf("%s\n",str1);
}

	
