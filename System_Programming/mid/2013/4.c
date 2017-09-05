#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	int fd;
	char buf[1];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(1);
	}

	close(0);
	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(2);
	}

//	dup(fd);
	while(scanf("%c",buf) > 0)
	{
		printf("%c",buf[0]);
	}
}

