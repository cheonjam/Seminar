#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	int status;

	if(fork()==0)
	{
		execlp("ps","ps","-axl",NULL);
		perror("exec()");
		exit(0);
	}

	wait(&status);

	printf("[%d]\n",status>>8);
}
