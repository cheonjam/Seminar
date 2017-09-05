#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX_COUNT 10
void sigint_signalhandler(int);

void main()
{

	int i=0;

	signal(SIGINT, sigint_signalhandler);
	for(i=1; i<MAX_COUNT; i++)
	{
		printf("\t[Child] sleep count #%d\n",i);
		sleep(1);
	}
	printf("\t[Child] process terminate! \n");
	exit(0);
}

void sigint_signalhandler(int sig)
{
	printf("\t[Child] receive SIGINT\n");
	exit(25);
}
