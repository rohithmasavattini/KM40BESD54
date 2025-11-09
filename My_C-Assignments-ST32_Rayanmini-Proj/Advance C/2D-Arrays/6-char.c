#include<stdio.h>
int main()
{
	char name[3][3];
	int i,j;
	printf("enter char matrix:\n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
	scanf("%c",&name[i][j]);
	}

	for(i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
        {
        printf("%c ",name[i][j]);
	}
	printf("\n");
	}
	return 0;
}



		

