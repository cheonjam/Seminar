#include "namedPipe.h"

void main(int argc, char *argv[])
{
	int n, fdpub, fd;
	char line[LINESIZE];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(1);
	}

	if((fdpub=open(PUBLIC,O_WRONLY))<0)
	{
		perror(PUBLIC);
		exit(2);
	}

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(3);
	}

	while((n=read(fd,line,LINESIZE))>0)
		write(fdpub,line,n);

	close(fdpub);
	unlink(PUBLIC);
}
