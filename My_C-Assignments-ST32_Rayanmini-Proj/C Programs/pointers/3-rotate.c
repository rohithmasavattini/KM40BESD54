#include<stdio.h>
int main()
{
        int x,y,z,t;
//      int *p1,*p2,*p3;
        printf("enter the values of x,y,z: ");
        scanf("%d %d %d",&x,&y,&z);
	int *p1=&x;
 	int *p2=&y;
        int *p3=&z;    
	t=*p1;
	*p1=*p2;
	*p2=*p3;
	*p3=t;
	printf("After rotate: %d %d %d\n",*p1,*p2,*p3);
}

