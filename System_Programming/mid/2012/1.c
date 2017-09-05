#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	int fd;
	char ch;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filname\n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	while(read(fd,&ch,1))
		printf("%c",ch);
}
