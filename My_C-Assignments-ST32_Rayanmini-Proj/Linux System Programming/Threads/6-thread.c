//WAP create two threads using pthreads and print even no and odd no alternatively.
#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *evenfun(void *arg);
void *oddfun(void *arg);

int flag=0;
int counter=0;
int main() {

    int res;
    int *range;
    pthread_t even_thread,odd_thread;
    void *thread_result;
    printf("enter range:");
    scanf("%d",range);

    printf("printing odd and even numbers using two threads\n");
    printf("Thread1\tThread2\n");

    res = pthread_create(&even_thread, NULL,evenfun,(void *)range);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&odd_thread, NULL,oddfun,range);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_join(even_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(odd_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("\nDone\n");
    exit(EXIT_SUCCESS);
}


void *evenfun(void *arg)
{
	while(counter <= *(int*)arg)
	{
		if(counter % 2==0 && !flag)
		{
			printf("%d\t",counter++);
			flag=1;
		}
		else
			sleep(1);
	}
    pthread_exit("exit");
}


void *oddfun(void *arg) {
  
    while(counter <= *(int*)arg)
    {
	    if(counter%2 !=0 && flag)
	    {
		    printf("%d\n",counter++);
		    flag=0;
	    }	    
	    else
		    sleep(1);
    }
    pthread_exit("exit");
}

