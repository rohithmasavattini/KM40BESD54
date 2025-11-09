#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	int fd;
	char buff[500];	
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("file open failed");
		_exit(1);
	}
	read(fd,buff,sizeof(buff));
	int w=0,l=0,i=0,j=0;
	int k=strlen(buff);
	while(k--)
	{
		if(buff[i]=='\n')
		{
			l++;
			w++;
		}
		if(buff[i]==' ')
		{
			w++;
		}
		i++;
	}
	printf(" %d %d %ld %s\n",l,w,strlen(buff),argv[1]);
	close(fd);
}

			

		

