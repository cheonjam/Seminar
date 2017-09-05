#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function();
int counter=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;

int main()
{
	int rc1, rc2;
	pthread_t thread1, thread2;

	if((rc1=pthread_create(&thread1, NULL, &function, NULL)))
		printf("thread creation failed: %d\n",rc1);

	if((rc2=pthread_create(&thread2, NULL, &function, NULL)))
		printf("Thread creation failed: %d\n",rc2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	exit(EXIT_SUCCESS);

}

void *function()
{
	int i;

	pthread_mutex_lock(&mutex1);
	counter++;
	for(i=0; i<0xFFFFFFF; i++)
		;
	printf("Counter value: %d\n",counter);
	pthread_mutex_unlock(&mutex1);
}


