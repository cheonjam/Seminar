#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_signalhandler(int sig);

void main()
{
	signal(SIGINT, sigint_signalhandler);
	signal(SIGQUIT, sigint_signalhandler);

	while(1);
}

void sigint_signalhandler(int sig)
{
	static int count=0;

	if(sig==SIGINT)
	{
		printf("control c pressed\n");
		count++;
	}
	else if(sig==SIGQUIT)
	{
		printf("control-c : %d\n",count);
		exit(0);
	}

}
