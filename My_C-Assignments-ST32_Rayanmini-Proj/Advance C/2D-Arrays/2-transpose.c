#include<stdio.h>
#define R 3
#define C 4
void fun(int m1[R][C],int m2[C][R]);
int main()
{
	int i,j;
	int m1[R][C],m2[C][R];
	printf("enter 3*4 matrix:\n");
	for(i=0;i<R;i++)
	for(j=0;j<C;j++)
	{
	scanf("%d",&m1[i][j]);	
	}
	fun(m1,m2);
	return 0;

}
void fun(int m1[R][C],int m2[C][R])
{
	int i,j;
	for(i=0;i<C;i++)
	   for(j=0;j<R;j++)
		m2[i][j]=m1[j][i];

	printf("transpose of matrix is :\n");
	for(i=0;i<C;i++)
	{
		for(j=0;j<R;j++)	
	   		printf(" %d",m2[i][j]);
		printf("\n");
	}
}
	



