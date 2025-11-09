#include<stdio.h>
#include<stdlib.h>
void *my_realloc(int *,size_t );
int main()
{
	int s=50,i;
	int *p=(int *)calloc(s,sizeof(int));
	printf("before realloc %p\n",p);
	if(p==NULL)
	{
		printf("Memory not available\n");
	}
	for(i=0;i<s;i++)
	{
		p[i]=i+1;
	}

	int *p1=my_realloc(p,100);
	printf("after realloc %p\n",p1); 

	for(i=0;i<100;i++)
	{
		printf("%d ",p1[i]);
	}
	free(p1);
		
}	

void * my_realloc(int *p, size_t len)
{
	int i;
	int *ptr=(int *)realloc(p,len*sizeof(int));
	if(ptr)
	{
		p=ptr;
	}
	else
		printf("memory not avialable\n");

	for(i=50;i<100;i++)
	{
		p[i]= i+1;
	}	
	//free(ptr);
	return p;
}

