#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	int fd,ch,i=0,j=1000;
	char buff[5000];
	fd = open(argv[1],O_RDONLY);
	if(fd<0)
	{	
	perror("file open failed");
	_exit(1);
	}

	while((ch=read(fd,buff,sizeof(buff)))>0)
	{
		while(j--)
	 	{
		 printf("%c",buff[i++]);
		}
	}
	//write(1,buff,strlen(bufff));
 	//printf("%s",buff);
	
	close(fd);
	_exit(0);
}


