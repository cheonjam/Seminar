#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int pid, read_fd, write_fd,fd[2], size;
	char str[BUFSIZ];

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s filename command \n",argv[0]);
		exit(-1);
	}

	if((pipe(fd))<0)
	{	
		perror("pipe() :");
		exit(-2);
	}

	if((pid=fork())<0)
	{
		perror("fork() :");
		exit(-3);
	}

	if(pid==0)
	{
		close(1);
		dup(fd[1]);
		execv(argv[2],argv+2);
		perror("execv :");
		exit(-4);
	}

	wait((int *)0);
	close(fd[1]);

	if((write_fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror("open ");
		exit(-5);
	}

	while((size=read(fd[0],str,sizeof(str)))>0)
		write(write_fd,str,size);
	close(fd[0]);
	close(write_fd);
}
