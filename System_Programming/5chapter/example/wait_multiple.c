#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
	int pid, pid1,pid2;

	if((pid1=fork())==0) /*child*/
		execl("/bin/echo","echo","this is","message one",(char *)0);
	printf("pid1 : %d\n",pid1);
	if((pid2=fork())==0) /*child*/
		execl("/bin/echo","echo","this is","message two",(char *)0);
	printf("pid2 : %d\n",pid2);
	printf("parent: waiting for children\n");

	//while(wait((int *)0)!=-1); /*null*/
	while((pid=wait((int *)0))!=-1)
		printf("%d \n",pid);

	printf("parent: all children terminated\n");
	exit(0);
}
