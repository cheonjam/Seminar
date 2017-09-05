#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define length BUFSIZ
void main(int argc, char **argv)
{
	int fd1, fd2, size;
	char buf[length];

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s origin_file copy_file\n",argv[0]);
		exit(-1);
	}

	if((fd1=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(-2);
	}

	if((fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0640))<0)
	{
		perror(argv[2]);
		close(fd1);
		exit(-3);
	}

	close(0);
	dup(fd1);
	close(1);
	dup(fd2);

	while(size=read(0,buf,length))
	{
		write(1,buf,size);
	}

	close(fd1);
	close(fd2);
}
