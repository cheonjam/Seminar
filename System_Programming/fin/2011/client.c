#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	char buf[BUFSIZ];
	int fd,size;


	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(0);
	}

	if((fd=open("SERVER",O_WRONLY))<0)
	{
		perror("open 1:");
		exit(1);
	}

	write(fd,argv[1],strlen(argv[1]));
	close(fd);
	
	if((fd=open("SERVER",O_RDONLY))<0)
	{
		perror("open 2:");
		exit(2);
	}

	while((size=read(fd,buf,sizeof(buf)))>0)
	{
		write(1,buf,size);
		memset(buf,0,sizeof(buf));
	}

	close(fd);

	exit(0);
}
