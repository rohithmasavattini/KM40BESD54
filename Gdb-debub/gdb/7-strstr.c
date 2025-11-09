#include<stdio.h>
int strstr_2(char s1[],char s2[]);
int cmp1(char s1[],char s2[],int i);
int main()
{
	char s1[100],s2[100];
	printf("enter a main string and substring:");
	scanf("%[^\n] %99s",s1,s2);
	int i=strstr_2(s1,s2);
	if(i==-1)
		printf("\"%s\" was not found in the main string\n",s2);
	else
		printf("\"%s\" was found at index %d\n:",s2,i);
}

int strstr_2(char s1[],char s2[])
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]==s2[0])
			if (cmp1(s1,s2,i)==1)
				return i;
	}
	return -1;
}

int cmp1(char s1[],char s2[],int i)
{
	i++;
	int k;
	for(k=1;s2[k]!='\0';k++,i++)
	{
		if(s1[i]!=s2[k])
			return 0;
	}
	return 1;
		
}
