#include<stdio.h>
char *my_strlower(char *str);
int main()
{
        char str[50];
	printf("enter a string: ");
        scanf("%s",str);
	my_strlower(str);
	printf("lowe case string: %s\n",str);
	return 0;
}

char *my_strlower(char *str)
{
	char *p=str;
        while(*str)
        {
                if(*str>='A' && *str<='Z')
                *str=*str+32;
		str++;
        }
	return p;
         
}

