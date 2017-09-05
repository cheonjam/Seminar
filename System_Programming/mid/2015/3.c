#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	int pid,fd;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(-1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT))<0)
	{
		perror(argv[1]);
		exit(-2);
	}
	
	if( (pid=fork())==0)
	{
		close(1);
		dup(fd);
		printf("[Child]\n");
		printf("parent process id : %d\n",getppid());
		printf("user effective id : %d\n",geteuid());
		printf("group effective id : %d\n",getegid());

		exit(1);
	}

	wait((int *)0);
	printf("[Partnt]\n");
	printf("process id : %d\n",getpid());
	printf("user id : %d\n",getuid());
	printf("group id : %d\n",getgid());

	close(fd);
}
