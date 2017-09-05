#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define MAXLENGTH 256

void copyfile();

void main(int argc, char **argv)
{
	if(argc<3) 
	{	
		fprintf(stderr, "Usage : %s in_file out_file\n",argv[0]);
		exit(-1);
	}

	copyfile(argv[1],argv[2]);
	
	exit(0);
}

void copyfile(char *source_file, char *target_file)
{
	int size=0;
	int fd1=0, fd2=0;
	char buf[MAXLENGTH];

	if( (fd1 = open(source_file, O_RDONLY)) < 0 )
	{
		perror(source_file);
		return ;
	}

	if( (fd2 = open(target_file, O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0)
	{
		perror(target_file);
		close(fd1);
		return ;
	}

	memset(buf, 0x00, sizeof(buf));
	while( (size = read(fd1, buf, MAXLENGTH)) > 0 )
		write(fd2, buf, size);

	close(fd1);
	close(fd2);
}
