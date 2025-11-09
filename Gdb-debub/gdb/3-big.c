#include <stdio.h>
int biggest(int num);
int main()
{
    int num,b,limit;
    printf("eneter the limit:");
    scanf("%d",&limit);
    b=biggest(limit);
    printf("Biggest number is:%d\n",b);
    return 0;
}    
int biggest(int limit)
{
    int i,big,num;
    printf("enetr %d numbers:",limit);
    for(i=1;i<=limit;i++)
    {
    scanf("%d",&num);
    if(num>big || i == 1)
    {
        big=num;
    }
    }
    return big;
}
