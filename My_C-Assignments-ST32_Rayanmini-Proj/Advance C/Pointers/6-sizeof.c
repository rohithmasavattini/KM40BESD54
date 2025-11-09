#include<stdio.h>
int main()
{
	int i=10,*ptr=&i;
        char ch='a',*ptr1=&ch;
	double d=2.22,*ptr2=&d;
	char arr[]="hello",*ptr3=arr;

	printf("size of int pointer= %lu\n",sizeof(ptr));
	printf("size of char pointer= %lu\n",sizeof(ptr1));
	printf("size of double pointer= %lu\n",sizeof(ptr2));
	printf("size of arr pointer= %lu\n",sizeof(ptr3));
	return 0;
}	
