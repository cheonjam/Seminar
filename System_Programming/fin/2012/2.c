#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
	int status;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s command option \n",argv[0]);
		exit(1);
	}

	if(fork()==0)
	{
		execv(argv[1],argv+1);
		perror("execv :");
		exit(2);
	}

	wait(&status);
	printf("Parent: child exit code = 0x%02d\n",status>>8);

	exit(0);
}
