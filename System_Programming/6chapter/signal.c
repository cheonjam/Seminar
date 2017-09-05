#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void child(int sig)
{
	printf("Child: signal[%d] occurred.\n",sig);
}

void main()
{
	int childPid;

	if((childPid=fork())==0)
	{
		signal(SIGQUIT,child);
		while(1)
		{
			fprintf(stderr,"a");
			sleep(1);
		}
	}

	sleep(2);
	kill(childPid,SIGQUIT);
}
