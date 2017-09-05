#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
	char buf[BUFSIZ];
	int size,fd[2];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s Execname\n",argv[0]);
		exit(1);
	}

	if(pipe(fd)<0)
	{
		perror("pipe ");
		exit(2);
	}

	if(fork()==0)
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);

		execv(argv[1], argv+1);
		perror("execv ");
		exit(3);
	}
	
	if(fork()==0)
	{
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		
		while((size=read(0,buf,sizeof(buf)))>0)
			write(1,buf,size);
		exit(4);
	}

	close(fd[0]);
	close(fd[1]);
	while(wait((int *)0)!=-1)
		;
	exit(0);
}
