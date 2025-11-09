#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	struct student *next;
}student;
student *reverse(student *);
student *delete(student *);
student *ascending(student *);
student *creatnode();
student *decending(student *); 
void traverse(); 
int main()
{
	student *Head=NULL,*new=NULL,*last=NULL;
	//char ch='y'
	while(1)
	{
	student *new=(student *)malloc(sizeof(student));
        //printf("enter number:\n");
        scanf("%d",&new->num);
	getchar();
	if(new->num==-1)
		break;
	new->next==NULL;
	//new=creatnode();
	if(Head==NULL)
		Head=last=new;
	else
		last->next=new;
		last=new;
	//printf("do you want to create another node?(y/n)");	
	//scanf("%d",&ch);
	}
	Head=decending(Head);
	traverse(Head);

	Head=ascending(Head);
	traverse(Head);
	Head=delete(Head);
	traverse(Head);
	Head=reverse(Head);
	traverse(Head);


}

/*student *creatnode()
{
	student *n=(student *)malloc(sizeof(student));
	printf("enter number:\n");
	scanf("%d",&n->num);
	getchar();
	n->next= NULL;
	return n;
}*/

void traverse(student *H)
{
	while(H)
	{
		printf("%d ",H->num);
		H=H->next;
	}
	printf("\n");	
}


student *ascending(student *Head)
{

	 student *T=Head,*Q=NULL;
	 for(T=Head;T->next!=NULL;T=T->next)
	 {
	 for(Q=Head;Q->next!=NULL;Q=Q->next)
	 {
                if(Q->num > Q->next->num)
         	{	
                int t;
                t=Q->num;
                Q->num=Q->next->num;
                Q->next->num=t;
                }       	
	 }
	 }

/*	while(T->next!=NULL)
	{
		Q=T->next;		
		while(Q!=NULL)
		{
		if(T->num > Q->num)
		{	
		int t;
		t=T->num;
		T->num=Q->num;
		Q->num=t;
		}
		Q=Q->next;
		}
		T=T->next;
	}*/
	return Head;
}


student *delete(student *Head)
{
	student *p=Head,*q=NULL;	
	while(p->next!= NULL)
	{
		if(p->num==p->next->num)
		{
			//q=p->next->next;
			//free(p->next);
			//p->next=q;
			q=p->next;
			p->next=q->next;
			free(q);
		}
		//else
		p=p->next;	
	}
	return Head;
}


student *reverse(student *Head)
{
	student *p,*q,*r;
	if(Head->next==NULL)
	{
		return Head;
	}
	if(Head->next->next==NULL)
	{
		p=Head;
		q=p->next;
		q->next=p;
		Head==NULL;
		Head->next=NULL;
		return q;
	}
	else
	{
	p=Head;
	q=p->next;
	r=q->next;
	while(q)
	{
	q->next=p;
	p=q;
	q=r;
	if(r)
	r=r->next;
	}
	Head->next=NULL;
	return p;
	}
}


student *decending(student *Head)
{

         student *T=Head,*Q=NULL;
         for(T=Head;T->next!=NULL;T=T->next)
         {
         for(Q=Head;Q->next!=NULL;Q=Q->next)
         {
                if(Q->num < Q->next->num)
                {
                int t;
                t=Q->num;
                Q->num=Q->next->num;
                Q->next->num=t;
                }
         }
         }
return Head;
}
