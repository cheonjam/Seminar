#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 20

void main(int argc, char *argv[])
{
	int fd[2], pid;
	char msgin[MSGSIZE], msgout[MSGSIZE]="\nHello, world\n";

	if(pipe(fd)==-1) /* creat pipe */
	{
		perror(argv[0]);
		exit(1);
	}

	if( (pid=fork()) >0) /* parent */
	{
		close(fd[0]);
		write(fd[1],msgout,MSGSIZE);
	}
	else if(pid==0) /* child */
	{
		close(fd[1]);
		read(fd[0],msgin,MSGSIZE);
		puts(msgin);
	}
	else
	{
		perror(argv[0]);
		exit(2);
	}
	exit(0);
}
