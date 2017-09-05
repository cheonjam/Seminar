#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	int pid,status,c_pid;

	if((pid=fork())==0)
	{
		execl("/bin/echo","echo","one",NULL);
		perror("execl (): ");
		exit(1);
	}

	if((pid=fork())==0)
	{
		execl("/bin/echo","echo","two",NULL);
		perror("execl (): ");
		exit(2);
	}

	if((pid=fork())==0)
	{
		execl("/bin/echo","echo","three",NULL);
		perror("execl (): ");
		exit(3);
	}
	
	if((pid=fork())==0)
	{
		execl("/bin/echo","echo","four",NULL);
		perror("execl (): ");
		exit(4);
	}

	while((c_pid=wait((&status)))!=-1)
		printf("[%d] %x\n",c_pid,status);
	printf("parent : all childeren terminated!!\n");
	exit(0);
}
