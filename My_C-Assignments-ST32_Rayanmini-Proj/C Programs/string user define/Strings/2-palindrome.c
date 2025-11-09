#include<stdio.h>
int palindrome( char str[]);
int main()
{
	char str[10];
	printf("enter a string:");
	scanf("%s",str);
	if(palindrome(str))
	printf("string is palindrome\n");
	else
		printf("not palindrome\n");
}

int palindrome(char str[])
{
	int i,j,n,count=0;
	for(i=0;str[i]!=0;i++);
	for(j=0;j<i/2;j++)
	{
		if(str[j]==str[i-j-1])
			count++;
	}
	if(count==j)
		return 1;
	else 
		return 0;
}
		
