#include<stdio.h>
int main()
{
	int m,n,i,j,p,q,k,sum=0;
	int m1[3][3],m2[3][3],m3[3][3];

	printf("enter number of rows and columns of matrix 1:\n");
	scanf("%d %d",&m,&n);
	printf("enter elements of matrix 1:\n");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&m1[i][j]);
	printf("enter number of rows and columns matrix 2:\n");
	scanf("%d %d",&p,&q);
	
	if(n!=p)
	printf("the matrices can't be multlipled with each other\n");
	else
	{	
	printf("enter elements of matrix 2:\n");
	for(i=0;i<p;i++)
        for(j=0;j<q;j++)
        scanf("%d",&m2[i][j]);

	for(i=0;i<m;i++)
	{
        for(j=0;j<n;j++)
	{
	m3[i][j]=0;	
	for(k=0;k<n;k++)
 	  {	
             m3[i][j] += m1[i][k]*m2[k][j];
	  }
	}
	}

	printf("product of the matrices:\n");
	for(i=0;i<m;i++)
	{
        for(j=0;j<q;j++)
	{
        printf(" %d",m3[i][j]);
	}
	printf("\n");
	}
	}
	return 0;
}
       

