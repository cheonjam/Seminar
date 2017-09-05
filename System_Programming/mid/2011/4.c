#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	int pid,c_pid,status;

	if((pid=fork())==0)
	{
		printf("Hello, World\n");
		exit(10);
	}

	c_pid=wait(&status);

	printf("Child pid : %d %d\n",pid,c_pid);
	printf("Exit code : %x\n",status);
}

