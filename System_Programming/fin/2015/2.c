#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void signalhandler(int sig);

void main(int argc, char *argv[])
{
	int size,fd;
	char str[BUFSIZ];

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s filename time \n",argv[0]);
		exit(1);
	}
	
	signal(SIGINT,signalhandler);
	signal(SIGQUIT,signalhandler);
	signal(SIGALRM, signalhandler);
	alarm(atoi(argv[2]));

	if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror("open :");
		exit(2);	
	}

	while(1)
	{
		memset(str,0,sizeof(str));
		if((size=read(0,str,sizeof(str)))==-1)
		{
			perror("read");
			exit(3);
		}
		write(fd,str,size);
	}
	close(fd);
}

void signalhandler(int sig)
{
	static int sigint=0, sigquit=0;

	if(sig==SIGINT)
		sigint++;
	else if(sig==SIGQUIT)
		sigquit++;
	else if(sig==SIGALRM)
	{
		printf("TIMEOUT!!\nSIGINT : %d\nSIGQUIT : %d\n",sigint,sigquit);
		exit(0);
	}
}
