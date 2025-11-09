#include<stdio.h>
char *my_strcon(char *str1,char *str2);
int main()
{
	int i;
	char str1[50],str2[50];
	printf("enter str1 and str2 :\n");
	scanf("%[^\n]s",str1);
	scanf(" %[^\n]s",str2);
	char *p=my_strcon(str1,str2);
	printf("after concatenation: %s",p);
	printf("\n");

}

char *my_strcon(char *str1,char *str2)
{
	char str3[50];
	char *p=str3;
	int n,m,i,j;
	printf("enter n and m index: ");
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		str3[i]=str1[i];
	}
	for(j=0;j<m;i++,j++)
	{
		str3[i]=str2[j];
	}
	str3[i]='\0';
	return p;
}

