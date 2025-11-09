#include<stdio.h>
int main()
{
        int i,n1,n2,p=1;
        printf("enter two numbers\n");
        scanf("%d%d",&n1,&n2);
        i=1;
        while(i<=n2)
        {

                p = p*n1;
                i++;
        }
        printf("%d\n",p);
}

