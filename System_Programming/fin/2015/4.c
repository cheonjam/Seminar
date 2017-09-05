#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

void main()
{
	int server_fd, client_fd,fd[2],size;
	char buf[BUFSIZ];

	mknod("SERVER",S_IFIFO|0666,0);

	while(1)
	{
		if((server_fd=open("SERVER",O_RDONLY))<0)
		{
			perror("open ");
			exit(1);
		}
	
		if(pipe(fd)<0)
		{
			perror("pipe ");
			exit(2);
		}

		while((size=read(server_fd,buf,sizeof(buf)))>0)
		{
			write(fd[1],buf,size);
			printf("%s\n",buf);
			memset(buf,0,sizeof(buf));
		}
		close(server_fd);
		close(fd[1]);

		fprintf(stderr,"client oren\n");
		if((client_fd=open("CLIENT",O_WRONLY))<0)
		{
			perror("open ");
			exit(2);
		}
		fprintf(stderr,"client open\n");
/*	
		size=read(server_fd,buf,sizeof(buf));
		write(1,buf,size);
		*/
		if(fork()==0)
		{
			close(0);
			dup(fd[0]);
			close(1);
			dup(client_fd);
			close(fd[0]);
			close(client_fd);

			execl("/bin/sort","sort",(char *)0);
			perror("execl :");
			sleep(1);
			exit(0);
		}

		wait((int *)0);
		close(fd[0]);
		close(client_fd);

	}
}
