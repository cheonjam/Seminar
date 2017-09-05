#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
	int fd[2],size;
	char str[256];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(0);
	}

	if(pipe(fd)<0)
	{
		perror(argv[0]);
		exit(1);
	}

	if(fork()==0)
	{
		write(fd[1],argv[1],strlen(argv[1])+1);
		exit(0);
	}

	close(fd[1]);
	wait((int *)0);

	memset(str,0,sizeof(str));
	while((size=read(fd[0],str,sizeof(str)))>0)
		write(1,str,size);

	close(fd[0]);
	exit(0);
}

