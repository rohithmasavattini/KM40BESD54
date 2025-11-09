#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int ID;
	char name[10];
	struct student *next;
}student;

student * creatnode();
void traverse(); 
int main()
{
	student *Head=NULL,*new=NULL,*last=NULL;
	char ch='y';
	while(ch=='y')
	{
	new=creatnode();
	if(Head==NULL)
		Head=last=new;
	else
		last->next=new;
		last=new;
	printf("do you want to create another node?(y/n)");	
	scanf("%c",&ch);
	getchar();
	}
	traverse(Head);

}

student *creatnode()
{
	student *n=(student *)malloc(sizeof(student));
	printf("enter ID name:\n");
	scanf("%d%s",&n->ID,n->name);
	getchar();
	n->next= NULL;
	return n;
}

void traverse(student *H)
{
	int c=0;
	while(H)
	{
		printf("%d  %s\n",H->ID,H->name);
		H=H->next;
		c++;
	}
	printf("noof nodes are %d\n",c);
}


