#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
	char name[20];
	int age;
}Information;

void main(int argc, char **argv)
{
	Information person;
	char tmp[20];
	int fd,fd2, age;

	if(argc<2)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_WRONLY|O_CREAT,0600))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	if((fd2=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(2);
	}
	lseek(fd,0,SEEK_END);

	while(1)
	{
		fprintf(stderr,"Input name : ");
		read(0,person.name,sizeof(person.name));
		person.name[strlen(person.name)-1]='\0';

		if(!strcmp(person.name,"-"))
			break;

		fprintf(stderr,"Input age : ");
		read(0,tmp,sizeof(tmp));
		tmp[strlen(tmp)-1]='\0';
		person.age=atol(tmp);

		write(fd,(Information *)&person,sizeof(Information));
		memset(person.name,0,sizeof(person.name));
		memset(tmp,0,sizeof(tmp));
	}

	while(read(fd2,(Information *)&person,sizeof(Information))>0)
	{
		fprintf(stderr,"%s %d\n",person.name, person.age);
	}

	close(fd);
	
}
