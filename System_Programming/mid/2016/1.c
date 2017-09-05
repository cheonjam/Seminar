#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX BUFSIZ

void main(int argc, char *argv[])
{
	char buf[MAX],tmp[MAX];
	int fd, i=0, j, size, count=0;

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s filename word \n",argv[0]);
		exit(-1);
	}

	if( (fd=open(argv[1],O_RDONLY)) < 0)
	{
		perror(argv[1]);
		exit(-2);
	}

	memset(tmp,0,sizeof(tmp));
	while(size=read(fd,buf,sizeof(buf)) > 0)
	{
		for(i=0, j=0; buf[i] ; i++)
		{
			if(buf[i]!=' ' && buf[i]!='\n')
				tmp[j++]=buf[i];
			else
			{
				if(!strcmp(tmp,argv[2]))
					count++;
				memset(tmp,0,sizeof(tmp));
				j=0;
			}
		}
	}
	
	printf("%d\n",count);

	close(fd);
}


