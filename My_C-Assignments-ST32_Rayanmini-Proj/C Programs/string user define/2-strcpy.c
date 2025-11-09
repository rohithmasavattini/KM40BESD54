#include<stdio.h>
void istrcpy(char str1[],char str2[]);
int main()
{
	char str1[100];
	char str2[100];
	printf("enter string2:");
	scanf("%s",str2);
	istrcpy(str1,str2);
}
void istrcpy(char str1[],char str2[])
{
	int i;
        for(i=0;str2[i]!='\0';i++)
        {
		str1[i]=str2[i];
	}
	str1[i]='\0';
	printf("string 1:%s\n",str1);

}

