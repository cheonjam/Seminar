#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define LOOP_COUNT 10

void sigint_signalhandler(int);

void main()
{
	int i=0;
	struct sigaction act, old_act;

	act.sa_handler=SIG_IGN;
	sigfillset(&act.sa_mask);
	sigaction(SIGINT, &act, 0);

	for(i=1; i<=LOOP_COUNT; i++)
	{
		printf("loop count[%d]\n",i);
		sleep(1);
	}

	sigaction(SIGINT, &old_act, (struct sigaction *)NULL);
	exit(0);
}

void sigint_signalhandler(int sig)
{
	if(sig==SIGINT)
		printf("SIGINT Receive!!\n");
}
