#include<stdio.h>
#include<stdlib.h>

typedef struct student 
{
	int num;
	struct student *next;
}student;
student *top=NULL;

void push();
void pop();
void traverse();

int main()
{
	student *new=NULL;
	int ch;
	while(1)
	{
		printf("choose 1)Push 2)Pop 3)Display 4)Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			traverse(top);
			break;
		case 4:
			exit(1);
		}
	}
}

void push()
{
	student *new=(student *)malloc(sizeof(student));
	printf("enter element to be pushed:\n");
	scanf("%d",&new->num);
	getchar();
	if(new==NULL)
	{
		printf("stack overflow\n");
		return;
	}
	new->next=top;
	top=new;
}

void pop()
{
	student *new=NULL;
	int temp;
        if(top==NULL)
        {
                printf("stack underflow\n");
		exit(1);
        }
	new=top;
	temp=new->num;
	top=top->next;
	free(new);
	printf("popped item is :%d\n",temp);

}


void traverse(student *top)
{
	student *ptr=top;
	if(ptr==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	printf("stack elements :\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->num);
		ptr=ptr->next;
	}
	printf("\n");

}





