#include<stdio.h>
int main()
{
        int n,num,p=0,n2=0,i;
        printf("Enter n numbers\n");
        scanf("%d",&n);
        i=1;
        while(i<=n)

        {
                scanf("\n%d",&num);
                if(num>0)
                p=p+num;
                else
			n2=n2+num;
                i++;
	}
	printf("sum of positive =%d\n",p);
	printf("sum of negative =%d\n",n2);
	return 0;
}

