#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	int fd[2], read_fd, pipe_size, file_size;
	char send_buf[BUFSIZ], rcv_buf[BUFSIZ];

	if(argc < 2 )
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(1);
	}
	
	if(pipe(fd)<0)
	{
		perror("pipe ");
		exit(2);
	}

	if(fork()==0)
	{
		close(fd[1]);
		while((pipe_size=read(fd[0],rcv_buf,sizeof(rcv_buf)))>0)
		{
			write(1,rcv_buf,pipe_size);
			memset(rcv_buf,0,sizeof(rcv_buf));
		}
		close(fd[0]);
		exit(0);
	}


	close(fd[0]);
	if((read_fd=open(argv[1],O_RDONLY))<0)
	{
		perror("read :");
		exit(3);
	}

	while((file_size=read(read_fd,send_buf,sizeof(send_buf)))>0)
	{
		write(fd[1],send_buf,file_size);
		memset(send_buf,0,sizeof(send_buf));
	}

	close(fd[1]);
	close(read_fd);
	
	exit(0);
}


