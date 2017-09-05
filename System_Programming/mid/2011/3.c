#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

void main(int argc, char **argv)
{
	int pid;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s exec_file \n",argv[0]);
		exit(1);
	}

	if((pid=fork())==0)
	{
		execv(argv[1],argv+1);
		perror(argv[1]);
		exit(2);
	}
	wait((int *)0);
}
