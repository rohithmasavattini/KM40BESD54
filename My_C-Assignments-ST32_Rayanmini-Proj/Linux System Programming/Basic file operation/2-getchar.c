#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char buff[2000];
	int fd;
	fd=open("abc",O_RDWR);
	if(fd<0)
	{
	perror("file open fail");
	_exit(1);
	}
	char ch;
	int i=0;
	while(ch=read(fd,buff,sizeof(buff))>0)
	{
		int j=1000;
		while(j--)
		{
		//write(1,buff,buff[i++]);
		printf("%c",buff[i++]);
		}
		//printf("%s",buff);
		
	}
	close(fd);
	_exit(0);

}
	

