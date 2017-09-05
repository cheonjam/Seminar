#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
	int pid, status;

	if(argc<2)
	{
		fprintf(stderr, "[ ./a.out file1] \n");
		exit(-1);
	}
	if((pid=fork())==0) /*child*/
		execl("/bin/cat","myCat",argv[1],((char *)0));

	while((wait(&status))!=-1);

	printf("parent : all children terminated\n");
	printf("child status = %s\n",status>>8);
	exit(0);
}
