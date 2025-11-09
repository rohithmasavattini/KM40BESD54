#include<stdio.h>
int stringcmp (char str1[],char str2[]);
int main()
{
	char str1[20],str2[20];
	printf("enter 2 strings:\n");
	scanf("%s",str1);
	scanf("%s",str2);
	if(stringcmp(str1,str2)==0)
		printf("strings are same\n");
	else
		printf("strings are not same\n");
	return 0;
}

int stringcmp(char str1[],char str2[])
{
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
			return (str1[i]-str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

