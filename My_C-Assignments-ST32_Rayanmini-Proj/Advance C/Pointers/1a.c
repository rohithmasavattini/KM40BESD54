#include<stdio.h>
int main()
{
	int a=10;
	int *ptr;
	ptr=&a;
	char *p;

	printf("adress:%p\nsize:%lu\nvalue:%d\n",ptr,sizeof(ptr),*ptr);
	printf("adress:%p\nsize:%lu\nvalue: %d\n",&a,sizeof(p),a);

}


