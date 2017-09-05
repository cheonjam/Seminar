#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void main(int argc, char **argv)
{
	int fd;

	if(argc<4)
	{
		fprintf(stderr,"Usage %s file_name position string\n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT,0640))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	lseek(fd,atol(argv[2]),SEEK_SET);
	if((write(fd,argv[3],strlen(argv[3])))<0)
	{
		perror(argv[3]);
		exit(3);
	}		

	close(fd);
}

