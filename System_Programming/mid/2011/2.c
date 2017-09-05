#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char **argv)
{
	char ch;
	int fd, fd2;

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s in_file out_file \n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(1);
	}

	if((fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror(argv[2]);
		exit(3);
	}

	while(read(fd,&ch,1))
	{
		if(ch=='\n')
			break;
		ch=ch+3;
		write(fd2,&ch,1);
	}
	write(fd2,&ch,1);

	close(fd);
	close(fd2);
}
