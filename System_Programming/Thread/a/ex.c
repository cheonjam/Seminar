#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *threadFunc(void *arg)
{
	char *s=(char *)arg;

	printf("%s\n",s);

	return (void *)strlen(s);

}



void main()
{
	pthread_t t1;
	int res;

	if(pthread_create(&t1,NULL,threadFunc,"zzzzzz\n")!=0)
		fprintf(stderr,"pthread create error\n");

	printf("Massage form main()\n");

	sleep(3);
	if(pthread_join(t1,(void *)&res)!=0)
		fprintf(stderr,"pthread join erron\n");

	printf("return code : %d\n",res);

	exit(0);
}
