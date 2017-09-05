#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	int status, pid;

	if(fork()==0)
	{
		execl("/bin/echo","echo","one",NULL);
		perror("exec1 :");
		exit(-1);
	}
	if(fork()==0)
	{
		execl("/bin/echo","echo","two",NULL);
		perror("exec2 :");
		exit(-2);
	}
	if(fork()==0)
	{
		execl("/bin/echo","echo","three",NULL);
		perror("exec3 :");
		exit(-3);
	}	
	if(fork()==0)
	{
		execl("/bin/echo","echo","four",NULL);
		perror("exec4 :");
		exit(-4);
	}

	while((pid=wait(&status))!=-1)
		printf("[%d]child exit code : %x\n",pid,status>>8);


	exit(0);
}

