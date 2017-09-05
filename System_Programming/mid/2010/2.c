#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	char ch;
	int fd, fd2;

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s copy_file origin_file \n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[2],O_RDONLY))<0)
	{
		perror(argv[2]);
		exit(2);
	}

	if((fd2=open(argv[1],O_WRONLY|O_CREAT|O_EXCL,0644))<0)
	{
		fprintf(stderr,"argv[1] %s : exist\n",argv[1]);
		close(fd);
		exit(3);
	}
	
	while(read(fd,&ch,1))
		write(fd2,&ch,1);

	close(fd);
	close(fd2);
}

	
