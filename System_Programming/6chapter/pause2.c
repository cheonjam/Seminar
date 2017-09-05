#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void main()
{
	void func(int);
	signal(SIGALRM,func);
	alarm(1);
	pause();
	fprintf(stderr,"good\n");
}
void func(int signum)
{
	fprintf(stderr,"in handler.\n");
}
