#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define EXIT_CODE 2

void main(int argc, char *argv[])
{
	int pid, ret, status;
	
	if( (pid=fork()) == 0)
	{
		printf("child: pid=%d ppid=%d exit_code=%d \n",getpid(), getppid(),EXIT_CODE);
		exit(EXIT_CODE);
	}

	printf("parent: wating for child = %d\n",pid);
	ret = wait(&status);

	printf("parent: return value=%d\n",ret);
	printf("child's status=%p\n", status);
	printf("and shifted=%x\n", (status >>8));

	exit(0);
}
