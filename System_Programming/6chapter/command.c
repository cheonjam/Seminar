#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage : %s command\n",argv[0]);
		exit(1);
	}

	signal(SIGINT, SIG_IGN);

	execlp("./echo1", argv[1], (char *)0);
//	execlp("default_envp", argv[1], (char *)0);
	perror("ececlz() : ");
	exit(2);
}

