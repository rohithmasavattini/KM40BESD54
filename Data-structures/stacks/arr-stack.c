#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void push(int s[],int *);
void pop(int s[],int *);
int main()
{
	int s[SIZE],top=-1;
	int ch;
	while(1)
	{
		printf("choose 1)Push 2)Pop 3)Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			push(s,&top);
			break;
		case 2:
			pop(s,&top);
			break;
		case 3:
			exit(1);
		}
	}
}

void push(int s[],int *top)
{
	if(*top==SIZE-1)
		printf("stack is full\n");
	else
	{
		int n;
		printf("enter enter element to push\n");
		scanf("%d",&n);
		++*top;
		s[*top]=n;
	}
}

void pop(int s[],int *top)
{
	if(*top==-1)
		printf("stack is empty\n");
	else
		printf("Popping %d\n",s[*top]);
       		--*top;
}
				
