#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void child(int sig)
{
	printf("Child: signal occurred.\n");
}

void parent(int sig)
{
	printf("Parent: signal occurred.\n");
}

void main()
{
	if(fork()==0)
	{
		signal(SIGQUIT, child);
		while(1)
			sleep(1);
	}

	signal(SIGQUIT, parent);
	while(1)
		sleep(1);
}
				
