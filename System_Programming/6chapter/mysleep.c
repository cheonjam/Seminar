#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

void sigint_signalhandler(int);
void sigalrm_signalhandler(int);
int mysleep(int);
static jmp_buf envp;

void main(int argc, char *argv[])
{
	int ret=0;
	signal(SIGINT, sigint_signalhandler);
	ret=mysleep(atoi(argv[1]));
	printf("remaining time : %d\n",ret);
	exit(0);
}

void sigint_signalhandler(int sig)
{
	if(sig==SIGINT)
		printf("Receive SIGINT signal\n");
}

int mysleep(int sec)
{
	void *old_set;
	old_set=signal
