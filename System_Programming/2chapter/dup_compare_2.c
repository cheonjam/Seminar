#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAXLENGTH 5

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

	fd2 = dup(fd1);

	while(1)
	{
		printf("1\n");
		if( (size1 = read(fd1, buf1, MAXLENGTH)) <= 0 )
			break;

		printf("2\n");
		if( (size2 = read(fd2, buf2, MAXLENGTH)) <= 0 )
			break;

		printf("3\n");
		if((size1==size2) && !strncmp(buf1,buf2,size1))
			fprintf(stderr,"buf1 data is buf2 data\n");
		else
			fprintf(stderr,"buf1 data is not buf2 data\n");

		printf("4\n");
		memset(buf1, 0x00, sizeof(buf1));
		memset(buf2, 0x00, sizeof(buf2));
	}
	close(fd1);
	close(fd2);

	exit(0);
}

