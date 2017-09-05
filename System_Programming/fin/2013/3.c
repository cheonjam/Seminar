#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signalhandler(int signal);

int pid,time;

void main(int argc, char *argv[])
{
	if(argc<3)
	{
		fprintf(stderr,"Usage : %s Filename Time\n",argv[0]);
		exit(1);
	}

	time=atoi(argv[2]);

	signal(SIGALRM,signalhandler);
	alarm(time);

	if((pid=fork())<0)
	{
		perror("fork ");
		exit(2);
	}

	if(pid==0)
	{
		execlp(argv[1],argv[1],NULL);
		perror("execlp :");
		exit(3);
	}

	wait((int *)0);
	printf("Parent : child exit within %d seconds\n",time);
	
	exit(0);
}

void signalhandler(int signal)
{
	if(signal==SIGALRM)
	{
		printf("Parent : child killed after %d seconds\n",time);
		kill(pid,SIGKILL);
		exit(0);
	}
}
