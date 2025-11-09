#include<stdio.h>
int main()
{
        int arr[5]={};
	int a[10]={2,4,5,6,7,8};
	int b[3]={1,2,3};
	int c[0]={};
	int d[0]={};
	int e[]={};
	int f['a'];
        int i;
	printf("%lu\n %lu\n %lu\n %lu\n %lu\n ",sizeof(arr),sizeof(a), sizeof(b),sizeof(c),sizeof(f));

        for(i=0;i<10;i++)
        {
	//	f[i]=i;
	
	a[10]=i;
	
        printf(" %d\t ",a[i]);
        }
        printf("\n"); 

}
