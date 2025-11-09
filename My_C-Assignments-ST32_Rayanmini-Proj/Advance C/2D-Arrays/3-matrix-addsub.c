#include<stdio.h>
int main()
{
	int m,n;
	printf("enter size of matrix:"); 
	scanf("%d %d",&m,&n);
	int i,j;
	int m1[m][n], m2[m][n], m3[m][n];
	printf("enter %d*%d matrix elements:\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)	
		scanf("%d",&m1[i][j]);
		
	}
	for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
	        scanf("%d",&m2[i][j]);     
        }
	//Add
	printf("matrix addition is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		m3[i][j]=m1[i][j]+m2[i][j];
	}
	for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
   		printf(" %d",m3[i][j]);
		
		printf("\n");
        }
	//sub
	printf("matrix subtraction is:\n");
	for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                m3[i][j]=m1[i][j]-m2[i][j];
        }
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                printf(" %d",m3[i][j]);

                printf("\n");
        }

	return 0;
			
}	


	
