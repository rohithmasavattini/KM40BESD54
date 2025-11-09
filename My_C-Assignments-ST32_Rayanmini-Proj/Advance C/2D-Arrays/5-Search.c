#include<stdio.h>
void search(int arr[2][3],int,int *,int *);
int main()
{
	int arr[3][3]={{1,2,3},
	    	       {4,5,6},
		       {7,8,9}};
	int i,j,n;
	printf("the given 3*3 array matrix form is: \n");
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	printf("%d ",arr[i][j]);
	printf("\n");
	}
	printf("enter searching element in above array: ");
	scanf(" %d",&n);
	search(arr,n,&i,&j);
	printf("The item you were searching for was found in %d row %d column\n",i,j);

}

void search(int arr[3][3],int n,int *i,int *j)
{
	int a,b;
	for(a=0;a<3;a++)
	{
	   for(b=0;b<3;b++)
	   {
	 	if(arr[a][b]==n)
		{
		*i=a;
		*j=b;
		}
	  }
	}
}	





