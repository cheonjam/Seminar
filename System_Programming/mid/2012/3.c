#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void main(int argc, char **argv)
{
	int pid;

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s origin_file copy_file\n",argv[0]);
		exit(1);
	}

	if((pid=fork())==0)
		execl("/bin/cp","insert",argv[1],argv[2],NULL);

	wait((int *)0);
	fprintf(stderr,"Child exited\n");

	exit(1);
}
