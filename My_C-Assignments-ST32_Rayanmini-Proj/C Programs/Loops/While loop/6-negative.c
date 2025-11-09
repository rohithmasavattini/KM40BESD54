#include<stdio.h>
int main()
{
	int i,a,p=0;
	printf("Enter positive numbers\n");
	i=0;
	while(1)
	{
		scanf("%d",&a);
		if(a>0)
		p=p+a;
		else 
			break;
		i++;	
		
	}
	printf("sum =%d\n",p);
	printf("number of positive numbers =%d\n",i);
	return 0;
}

