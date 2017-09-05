#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	char buf[1];
	int fd;
	
	if(argc<2)
	{
		fprintf(stderr,"Usage : %s file\n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror(argv[1]);
		exit(2);
	}
	
	close(1);
	dup(fd);

	printf("Hello, World.\n");
	printf("Test input.\n");
}

