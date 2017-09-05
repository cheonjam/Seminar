#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 100

void main(int argc, char **argv)
{
	int fd, size;
	char buf[MAX];

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename \n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	while(size=read(0,buf,sizeof(buf)))
	{
		if(*buf=='.')
			break;
		write(fd,buf,size);
		memset(buf,0,strlen(buf));
	}

	close(fd);
}
