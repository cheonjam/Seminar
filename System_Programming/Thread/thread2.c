#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *t_function(void *data)
{
	char a[100000];
	int num = *((int *)data);
	static int k=0;

	printf("(%d)Thread Start \n",k++);
	sleep(2);
	printf("thread end\n");
}

int main()
{
	pthread_t p_thread[3];
	int thr_id, status, a=100;

	printf("Before Thread\n");
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
	if(thr_id<0)
	{
		perror("thread create error: ");
		exit(0);
	}

	sleep(2);
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)&a);
	if(thr_id<0)
	{
		perror("thread create error: ");
		exit(0);
	}

	sleep(2);
	thr_id = pthread_create(&p_thread[2], NULL, t_function, (void *)&a);
	if(thr_id<0)
	{
		perror("thread create error: ");
		exit(0);
	}

	pthread_detach(p_thread[0]);
	pthread_detach(p_thread[1]);
	pthread_detach(p_thread[2]);
	pause();
	fprintf(stderr,"main exit\n");
	return 0;
}

