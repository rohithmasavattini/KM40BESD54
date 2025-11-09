#include<stdio.h>
#define MACHINE linux

int main()
{
#if MACHINE==windows
	printf("Microsoft Windows Welcomes You\n");
#endif
#if MACHINE==linux
	printf("Linux welcomes You\n");
#endif
#if MACHINE==mac
	printf("Mac welcomes you\n");
#endif
}
