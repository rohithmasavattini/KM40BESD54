#include<stdio.h>
int main()
{
	int n,i,elem,lar,sm;
	printf("enter n elements: \n");
	scanf("%d",&n);
	printf("enter first element \n");
	scanf("%d",&elem);
	lar=elem;
	sm=elem;
	for(i=1;i<=n-1;i++)
	{
		printf("enter another element\n");
		scanf("%d",&elem);
		if(elem>lar)
			lar=elem;
		if(elem<sm)
			sm=elem;
	}
	printf("large =%d\n",lar);
	printf("small=%d\n",sm);
}

