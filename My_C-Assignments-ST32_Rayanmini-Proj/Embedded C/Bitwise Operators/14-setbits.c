#include<stdio.h>
void binary_x(int x);
void binary_y(int y);
void setbits(int x,int y,int n,int p);

int main()
{
	int n,p;
	int x,y;
	printf("enter x and y values:");
	scanf("%d%d",&x,&y);
	printf("enter n and p:");
	scanf("%d%d",&n,&p);
	binary_x(x);
        binary_y(y);

	setbits(x,y,n,p);
	return 0;

}
void binary_x(int x)
{
	int i,mask;
	printf("x=");
	for(i=7;i>=0;i--)
	{
		mask=1<<i;
		if(mask&x)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

void binary_y(int y)
{
        int i,mask;
	printf("y=");
        for(i=7;i>=0;i--)
        {
                mask=1<<i;
                if(mask&y)
                        printf("1");
                else
                        printf("0");
        }
        printf("\n");
}

void setbits(int x,int y,int n,int p)
{
	int z,a,i,mask;

	mask=~(~0<<n)<<p-n+1;
	z=(x & ~mask)|(y << p-n+1-1);

	printf("setbits n=%d,p=%d x= ",n,p);
	for(i=7;i>=0;i--)
	{
		a=1<<i;
		if(a&z)
		printf("1");
		else
			printf("0");

	}
	printf("\n");

}
	



