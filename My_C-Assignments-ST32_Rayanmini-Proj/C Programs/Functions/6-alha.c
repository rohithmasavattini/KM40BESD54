#include<stdio.h>
int alpha_num(char ch);
int main()
{
	char ch;
	printf("enter alphabet or number: ");
	scanf("%c",&ch);
	ch=alpha_num(ch);
	if(ch)
	printf("alphanumeric\n");
	else
		printf("not alphanumeric\n");


}

int alpha_num(char ch)
{
	if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
		return 1;
	return 0;
}
	
