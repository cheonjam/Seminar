#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void main(int argc, char **argv)
{
	int fd1=0, fd2=0, fd3=0, offset=0;
	char buf;

	if( argc < 4)
	{
		fprintf(stderr, "[ ./a.out file1 file2 file3] \n");
		exit(-1);
	}

	if( (fd1 = open(argv[1], O_RDONLY)) < 0 )
	{
		perror(argv[1]);
		exit(-1);
	}

	if( (fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644)) < 0 )
	{
		perror(argv[2]);
		exit(-1);
	}

	if( (fd3 = open(argv[3], O_WRONLY | O_CREAT | O_EXCL, 0644)) < 0 )
	{
		perror(argv[3]);
		exit(-1);
	}

	while(1)
	{
		lseek(fd1,offset++,SEEK_SET);
		if(!read(fd1,&buf,sizeof(buf)))
			break;

		if(offset%2)
			write(fd2,&buf,sizeof(buf));
		else
			write(fd3,&buf,sizeof(buf));
	}

	close(fd1);
	close(fd2);

	exit(0);
}
