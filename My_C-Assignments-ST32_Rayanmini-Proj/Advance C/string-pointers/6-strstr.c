#include<stdio.h>
int strstr_2(char *s1,char *s2);
int cmp1(char *s1,char *s2,int i);
int main()
{
	char s1[100],s2[100];
	printf("enter a main string and substring:");
	scanf("%99s%99s",s1,s2);
	int i=strstr_2(s1,s2);
	if(i==-1)
		printf("\"%s\" was not found in the main string",s2);
	else
		printf("\"%s\" was found at index %d\n:",s2,i);
}
int strstr_2(char *s1,char *s2)
{

	int i;
	for(i=0;*s1!='\0';i++)
	{
		if(*s1==*s2)
		{
			if (cmp1(s1,s2,i)==1)
				return i;
		}
		s1++;
		
	}
	return -1;

}

int cmp1(char *s1,char *s2,int i)
{
	i++;
	s1++;
	s2++;
	for(;*s2!='\0';i++)
	{
		if(*s1!=*s2)
			return 0;
		s1++;
		s2++;
		i++;
	}
	return 1;
		
}
	
