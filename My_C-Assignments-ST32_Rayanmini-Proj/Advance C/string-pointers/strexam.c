#include<string.h>
#include<stdio.h>
int strstr_2(char *s,char *s1,char *s2);
int cmp1(char *s,char *s1,char *s2);
int strreplace(char *s,char *s2);
int main()
{
        char s[100],s1[20],s2[20];
        printf("enter a main string: ");
	scanf("%[^\n]s",s);	
	printf("enter first substring: ");
        scanf("%s",s1);
	printf("enter second substring: ");
	scanf("%s",s2);
        
	int i=strstr_2(s,s1,s2);
	if(i==0)
        	puts(s);
	else
                printf("was not found\n");
}

int strstr_2(char *s,char *s1,char *s2)
{
        int i;
        for(;*s!='\0';s++)
        {
                if(*s==*s1)
                        cmp1(s,s1,s2);	
			
        }
        return 0;
}

int cmp1(char *s,char *s1,char *s2)
{
	s++;
	s1++;
        for(;*s1!='\0';s1++)
        {
                if(*s!=*s1)
                        return 1;
        }
	if(strreplace(s,s2)==1)
	return 1;
}

int strreplace(char *s,char *s2)
{
	int n;
	s--;
	for(;*s2!=0;s2++,s++)
	{
		*s=*s2;
	}
	return 1;
}
	
