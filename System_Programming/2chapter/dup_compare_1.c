#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXLENGTH 256

void main(int argc, char *argv[])
{
	int size1=0, size2=0, fd1=0, fd2=0;
	char buf1[MAXLENGTH], buf2[MAXLENGTH];

	if( argc < 2)
	{
		fprintf(stderr,"Usage :%s filename\n");
		exit(-1);
	}
	
	if( (fd1 = open(argv[1], O_RDONLY)) < 0 )
	{
		perror(argv[1]);
		exit(-2);
	}

	if( (fd2 = open(argv[1], O_RDONLY)) < 0 )
	{
		perror(argv[1]);
		close(fd1);
		exit(-3);
	}

	while(1)
	{
		if( (size1 = read(fd1, buf1, MAXLENGTH)) <= 0 )
			break;

		if( (size2 = read(fd2, buf2, MAXLENGTH)) <= 0 )
			break;

		if((size1==size2) && !strncmp(buf1,buf2,size))
			fprintf(stderr,"buf1 data is buf2 data\n");
		else
			fprintf(stderr,"buf1 data is not buf2 data\n");
	}
	close(fd1);
	close(fd2);

	exit(0);
}

