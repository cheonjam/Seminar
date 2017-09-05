#include "namedPipe.h"

void main(int argc, char *argv[])
{
	int fdpub, n, i;
	char line[LINESIZE];

	mknod(PUBLIC, S_IFIFO|0666,0);

	if((fdpub=open(PUBLIC,O_RDONLY))<0)
	{
		perror(PUBLIC);
		exit(1);
	}

	while((n=read(fdpub,line,LINESIZE))>0)
		write(1,line,n);

	close(fdpub);
}
