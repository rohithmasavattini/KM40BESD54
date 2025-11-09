#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int i;
	for(i=1;i<argc;i++)
	write(1,argv[i],strlen(argv[i]));
	//write(1,argv[2],strlen(argv[2]));
	return 0;
}



