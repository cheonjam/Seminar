#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	int pid, st;

	if(fork()==0)
	{
		execl("./chdild", "child", (char *)0);
		perror("fork error");
		exit(-1);
	}

	pid=wait(&st);
	printf("pid=[%d],status=[%x]\n",pid,st);
}
