#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	int pid, status;

	if(!(pid=fork())) //child
		execlp("ls","ls","-l",(char *)0);
	printf("parent : wating for children\n");

	while(wait(&status) != -1);

	printf("parent all children terminated\n");
	printf("child status = %d\n",status>>8);
	exit(0);
}
