#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int fd;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(-1);
	}

	if((fd=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644))==-1)
	{
		perror(argv[1]);
		exit(-2);
	}
	
	if(fork()==0)
	{
		close(1);
		dup(fd);
		execl(argv[1],argv[1],NULL);
		perror(argv[1]);
		exit(-3);
	}
	
	wait((int *)0);
	close(fd);

	exit(0);
}
