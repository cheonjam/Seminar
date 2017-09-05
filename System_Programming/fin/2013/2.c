#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalhandler(int signal);

void main(int argc, char *argv[])
{
	if(argc<2)
	{
		fprintf(stderr,"Usage : %s time \n",argv[0]);
		exit(1);
	}

	signal(SIGINT,SIG_IGN);
	signal(SIGALRM,signalhandler);
	alarm(atoi(argv[1]));

	while(1)
		;
}

void signalhandler(int signal)
{
	if(signal==SIGALRM)
	{
		printf("Time out\n");
		exit(0);
	}
}



