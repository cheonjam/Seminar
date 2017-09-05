#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int fd[2], read_fd, file_size, size;
	char str[BUFSIZ];

	if(argc < 2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(0);
	}

	if(pipe(fd)<0)
	{
		perror("pipe ");
		exit(1);
	}

	if(fork()==0)
	{
		if((read_fd=open(argv[1],O_RDONLY))<0)
		{
			perror("read :");
			exit(2);
		}

		while((file_size=read(read_fd,str,sizeof(str)))>0)
			write(fd[1],str,file_size);
		
		close(read_fd);
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}

	close(fd[1]);
	while((size=read(fd[0],str,sizeof(str)))>0)
		write(1,str,size);
	close(fd[0]);

	exit(0);
}


