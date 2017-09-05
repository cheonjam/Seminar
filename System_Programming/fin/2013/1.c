#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signalhandler(int signal);

void main()
{
	int size;
	char buf[BUFSIZ];

	signal(SIGINT,signalhandler);
	signal(SIGQUIT,signalhandler);
	
	while(1)
	{
		size=read(0,buf,sizeof(buf));
		write(1,buf,size);
	}

}

void signalhandler(int signal)
{
	if(signal==SIGINT)
		printf("control C\n");
	if(signal==SIGQUIT)
	{
		printf("control \\\n");
		exit(0);
	}
}
