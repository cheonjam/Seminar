#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	int pid=0, status=0;

	if((pid=fork())==0)
	{
		execlp("./rcv_signal","rcv_signal",(char *)NULL);
		perror("execlp():");
		exit(2);
	}

	else if(pid>0)
	{
		sleep(2);
		kill(pid,SIGINT);
		printf("[Parent]: Send SIGINT\n");
		wait(&status);
		printf("[Parent]: Child killed by Parent. [%x] \n",stauts);
	}
}
