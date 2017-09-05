#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char **argv)
{
	int count, fd;
	char buf[512];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror(argv[1]);
		exit(2);
	}
	close(1);
	dup(fd);

	while((count=read(0,buf,512))>0)
	{
		buf[count]=0;
		printf("%s",buf);
	}

	close(fd);
}
