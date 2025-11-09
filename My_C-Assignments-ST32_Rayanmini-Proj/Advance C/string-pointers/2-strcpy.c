#include<stdio.h>
char *my_strcpy(char *str1,char *str2);
int main()
{
	char str1[50]="kernel";
	char str2[50];
	printf("enter source string:");
	scanf("%[^\n]s",str2);
	my_strcpy(str1,str2);
	printf("destination string:%s\n",str1);
	return 0;
}

char *my_strcpy(char *str1,char *str2)
{
	char *p;
	p=str1;
        while(*str2)
        {
		//*(str1+i)=*(str2+i);
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1='\0'; 
	return p;		
}

