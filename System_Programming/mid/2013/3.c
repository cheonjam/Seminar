#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 100

void main(int argc, char **argv)
{
	char ch,buf[MAX];
	int fd,i=0,found=0;

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s filename string\n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	memset(buf,0,sizeof(buf));

	while(read(fd,&ch,1)>0)
	{
		if(ch!=' ' && ch !='\n')
			buf[i++]=ch;
		else
		{
			if(!strcmp(buf,argv[2]))
				found=1;
			memset(buf,0,sizeof(buf));
			i=0;
		}
	}

	if(found)
		printf("Found\n");
	else
		printf("Not Found\n");

	close(fd);
}
						
