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
student * insertatpos(student *,int);
student * insertbeforekey(student *,int);
student * insertafterkey(student *,int);
student * deletebeforekey(student *,int);
int main()
{
	student *Head=NULL,*new=NULL,*last=NULL;
	int choice,p,key;
	while(1)
	{
		printf("\n1.Create node\n");
		printf("2.Display\n");
		printf("3.Insert at a position\n");
		printf("4.Insert before a key\n");
		printf("5.Insert after a key\n");
		printf("6.Delete a node with given key\n");
		printf("7.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				new=creatnode();
        			if(Head==NULL)
                		Head=last=new;
       				else
              			  last->next=new;
           	  		  last=new;
      				  //traverse(Head);
				  break;
			case 2:
				   traverse(Head);
				   break;
			case 3:
		      		   printf("enter the position for inserting a new node:\n");
      				   scanf("%d",&p);
           			   Head=insertatpos(Head,p);
   				  //traverse(Head);
				   break;
			case 4:
		        	   printf("enter key(ID) for Inserting before key :\n");
    			    	   scanf("%d",&key);
      				   Head=insertbeforekey(Head,key);
  			           //traverse(Head);
				   break;
			case 5:
				    printf("enter key(ID) for Inserting after key :\n");
			            scanf("%d",&key);
   				    Head=insertafterkey(Head,key);
    				    //traverse(Head);
				    break;
			case 6:
				    printf("enter key(ID) for deletion :\n");
                                    scanf("%d",&key);
                                    Head=deletebeforekey(Head,key);
                                    //traverse(Head);
                                    break;
			case 7:
				    exit(1);
			default :
				    printf("wrong choice\n\n");
		}
	}
}

student *creatnode()
{
	student *n=(student *)malloc(sizeof(student));
	printf("enter ID,name:\n");
	scanf("%d%s",&n->ID,n->name);
	getchar();
	n->next= NULL;
	return n;
}

void traverse(student *H)
{
	while(H)
	{
		printf("ID:%d\tName:%s\n",H->ID,H->name);
		H=H->next;
	}

}

student * insertatpos(student *Head,int  p)
{
	student *new,*H=Head;
	int i=1;
	new=creatnode();
	if(p==1)
	{
		new->next=H;
		return new;
	}
	while(i<p-1)
	{
		H=H->next;
		i++;
	}
	new->next=H->next;
	H->next=new;
	return Head;

}

student * insertbeforekey(student *Head,int key)
{
        student *new,*H=Head;
        new=creatnode();
	if(Head->ID==key)
	{
		new->next=H;
		//H=new;
		return new;
	}
	while(H->next->ID!=key)
	{
		H=H->next;
	}
	new->next=H->next;
	H->next=new;
	return Head;
}

student * insertafterkey(student *Head,int key)
{
        student *new,*H=Head;
        new=creatnode();
       /* if(Head->ID==key)
        {
		new->next=H->next;
                H->next=new;
                return Head;
        }*/
        while(H->ID!=key)
        {
                H=H->next;
        }
        new->next=H->next;
        H->next=new;
	return Head;
}

student *deletebeforekey(student *Head,int key)
{
	student *T,*Q;
	T=Head;
	if(Head->ID==key)
	{
		Q=Head->next;
		free(Head);
		return Q;
	}
	while(T->next->ID!=key)
	{
		T=T->next;
	}
	Q=T->next;
	T->next=Q->next;
	free(Q);
	return Head;
}

		

	



