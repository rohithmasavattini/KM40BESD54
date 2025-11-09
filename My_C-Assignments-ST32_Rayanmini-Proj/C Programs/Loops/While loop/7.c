#include<stdio.h>
int main()
{
        int i,n,sum=0,a;
        printf("Enter  numbers\n");
	scanf("%d",&n);
     	i=1;
        while(i<=n)
        {
                scanf("%d",&a);
                if(a>0)
		{
	       		sum=sum+a;
            		 i++;
		}	
	
	}
        printf("sum =%d\n",sum);

} 
