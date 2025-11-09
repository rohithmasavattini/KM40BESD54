#include<stdio.h>
int stringword(char str[]);
int main()
{
	int word;
	char str[20];
	printf("enter a string:");
	scanf("%[^\n]s",str);
	word=stringword(str);
	printf("no of words in string: %d\n",word);

}
int stringword(char str[])
{
 	int i,word=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]==32)
			word++;
	}
	if(i>0)
		word++;

	return word;
}

