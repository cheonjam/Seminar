#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void main(int argc, char *argv[])
{
	char buf[BUFSIZ];
	int fd[2],size;

	if(argc<2)
	{
		size=read(0,buf,sizeof(buf));
		write(1,buf,size);
		exit(0);
	}

	if(pipe(fd)<0)
	{
		perror("pipe :");
		exit(1);
	}
	
	if(fork()==0)
	{
		close(1);
		dup(fd[1]);
		close(fd[1]);
		close(fd[0]);

		execl("/bin/cat","/bin/cat",argv[1],NULL);
		perror("execl :");
		exit(2);
	}
	else
	{	
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
	}

	execl("/bin/cat","cat",NULL);
	perror("execl ");
	exit(3);
}
