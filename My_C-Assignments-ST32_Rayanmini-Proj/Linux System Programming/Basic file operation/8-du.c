#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd[2];
	char buff[500];	
	fd[0]=open(argv[2],O_RDONLY);
	if(fd[0]<0)
	{
		perror("file open failed");
		_exit(1);
	}
	read(fd[0],buff,sizeof(buff));
        int i,k=strlen(buff);
	if(argv[1]=="-b");
	printf("%d %s\n",k,argv[2]);

	close(fd[0]);
	
}

