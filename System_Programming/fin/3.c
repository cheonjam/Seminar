#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc, char **argv)
{
	int pid;

	if(argc<4)
	{
		fprintf(stderr,"Usage : %s exec_name file1 file2 \n",argv[0]);
		eit(1);
	}

	if((pid=fork())==0)
	{
		execv("/usr/bin/cmp",argv+1);
		perror("execv ()");
		exit(2);
	}

	wait((int *)0);
	fprintf(stderr,"child exited.\n");

	exit(0);
}
