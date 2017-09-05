#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid,ppid;

	if( (pid=fork())==-1)
	{
		perror("for() : ");
		exit(-1);
	}

	if(pid == 0)
	{
		sleep(2);
		pid=getpid();
		ppid=getppid();
		printf("C: %d, p=%d\n",pid,ppid);
		exit(0);
	}
	else
	{
		pid=getpid();
		ppid=getppid();
		printf("P: %d, p=%d\n",pid,ppid);
	}
}


