#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter=0;
void *doSomeThing(void *argv);

int main()
{
	int i=0, err;

	while(i<2)
	{
		err=pthread_create(&(tid[i]),NULL, &doSomeThing, NULL);
		if(err!=0)
			printf("\n can't create thread : [%s]",strerror(err));
		i++;
	}

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	return 0;
}

void *doSomeThing(void *argv)
{
	unsigned long i=0;

	counter += 1;

	printf("Job %d started\n",counter);

	for(i=0; i<(0xFFFFFFF); i++)
		;
	printf("Job %d finished.\n",counter);

	return NULL;
}

