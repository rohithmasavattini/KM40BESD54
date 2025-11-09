
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	char buff[10];
	fd = open("abc",O_RDONLY);
	if(fd<0)
	{	
	perror("file open failed");
	_Exit(1);
	}
	read(fd,buff,10);
	//printf("buff:%s\n",buff);
	write(1,buff,10);

}


