#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SERVER "SERVER"

void main(int argc, char *argv[])
{
	int fd, fd_data, read_size;
	char buf[BUFSIZ];

	mknod(SERVER,S_IFIFO|0666,0);

	while(1)
	{
			/*
		if((fd=open(SERVER,O_RDONLY))==-1)
		{
			perror(SERVER);
			exit(1);
		}
		*/
			
		memset(buf,0x00,sizeof(buf));
		fd=open(SERVER,O_RDONLY);
		
		read(fd,buf,sizeof(buf));
		close(fd);

		printf("Client has requested [%s]\n",buf);
		if((fd=open("SERVER",O_WRONLY))==-1)
		{
			perror("open :");
			exit(1);
		}

		if((fd_data=open(buf,O_RDONLY))<0)
		{
			write(fd, "ERROR : No Such File\n",21);
			perror(buf);
			close(fd);
			continue;
		}

		memset(buf,0x00,sizeof(buf));

		while((read_size=read(fd_data,buf,sizeof(buf)))>0)
		{
			write(fd,buf,sizeof(buf));
			memset(buf,0x00,sizeof(buf));
		}

		close(fd_data);
		close(fd);
	}
}
