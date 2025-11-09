#include<stdio.h>
void isprime(int,int);
int main()
{
	int n1,n2;
	printf("eneter 2 numbers:\n");
	scanf("%d%d",&n1,&n2);
	isprime(n1,n2);
	return 0;
}
void isprime(int n1,int n2)
{
	int j;
	 while(n1<n2)
	 {
		count=0; 
		for(j=2;j<=n1;j++)
		{
			if(n1%j==0)
				count++;
		}
		if(count==1)
		printf("%d ",n1);	
		n1++;
	 }
}


