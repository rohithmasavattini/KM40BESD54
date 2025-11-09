#include<stdio.h>
void strlower(char str[]);
int main()
{
        char str[50];
        int i;
        printf("enter a string: ");
        scanf("%s",str);
	strlower(str);
}

void strlower(char str[])
{
	int i;
        for(i=0;str[i]!='\0';i++)
        {
                if(str[i]>='A' && str[i]<='Z')
                str[i]=str[i]+32;
        }
                printf("lowe case: %s\n",str);
}

