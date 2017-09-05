#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, char **argv)
{
	int pid;

	if((pid=fork())==0)
	{
		execl("/bin/ls","ls","-l",NULL);
		perror("execl () :");
		exit(1);
	}

	wait((int *)0);
}
