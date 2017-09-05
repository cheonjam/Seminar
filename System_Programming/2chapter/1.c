#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void main(int argc, char **argv)
{
	int fd1=0, fd2=0, offset=-1;
	char buf;

	if( argc < 2)
	{
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(-1);
	}

	if( (fd1 = open(argv[1], O_RDONLY)) < 0 )
	{
		perror(argv[1]);
		exit(-2);
	}

	if( (fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0 )
	{
		perror(argv[2]);
		exit(-2);
	}

	while(1)
	{
		memset(&buf,0x00,sizeof(buf));

		if(lseek(fd1,offset--,SEEK_END)==-1)
			break;
		read(fd1,&buf,sizeof(buf));
		write(fd2,&buf,sizeof(buf));
	}

	close(fd1);
	close(fd2);
	exit(0);
}
