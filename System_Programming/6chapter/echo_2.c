#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_signalhandler(int);

void main()
{
	int size=0;
	char temp[BUFSIZ];

	signal(SIGINT, sigint_signalhandler);
	signal(SIGQUIT, sigint_signalhandler);

	for(;;)
	{
		size = read(0, temp, BUFSIZ);
		write(1, temp, size);
	}

}

void sigint_signalhandler(int sig)
{
	if(sig == SIGINT)
	{
		printf("SIGINT Receive\n");
		exit(1);
	}
	else if(sig == SIGQUIT)
		printf("SIGQUIT Receive and process continue!!!\n");	
}
