#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct _Information
{
	char name[20];
	int age;
}Information;

void main(int argc, char **argv)
{
	Information a;
	char tmp[20];
	int fd;

	if(argc<2)
	{
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		exit(-1);
	}

	if( (fd=open(argv[1],O_WRONLY|O_CREAT|O_EXCL,0640)) < 0 )
	{
		perror(argv[1]);
		exit(-2);
	}

	while(1)
	{
			
		fprintf(stderr,"Input name : ");
		read(0,a.name,sizeof(a.name));
		a.name[strlen(a.name)-1]='\0';

		if(!strcmp(a.name,"*"))
			return ;

		fprintf(stderr,"Input age : ");
		read(0,tmp,sizeof(tmp));
		tmp[strlen(tmp)]='\0';
		a.age=atoi(tmp);
	
		write(fd, (Information *)&a, sizeof(Information));
		memset(a.name,0,sizeof(a.name));
	}

	close(fd);
}
