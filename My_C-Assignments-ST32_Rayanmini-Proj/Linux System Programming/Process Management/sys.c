#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<errno.h>
void sys(const char *cmd);

int main(int argc,char *argv[])
{
	int i;
	for(i=1;i<argc;i++)
	{
		sys(argv[i]);
		printf("\n");
	}
	_exit(0);
}
void sys(const char *cmd)
{
	pid_t pid;
	pid=fork();
	if(pid==0)
		execl("/bin/bash","bash","-c",cmd,NULL);
	else
		wait(NULL);
}

