#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX 20

int DivideCommand(char *buf, char **argv, char **path);
void Execute(char **argv);
void Initialize(char *buf, char **argv);

void main()
{
	char buf[BUFSIZ];
	char *argv[MAX];
	char *path[2]={"/bin","/usr/bin"};

	mknod("CLIENT",S_IFIFO|0666,0);

	memset(argv,0,sizeof(argv));

	while(1)
	{
		write(1,"% ",2);
		read(0,buf,sizeof(buf));

		if(DivideCommand(buf,argv,path)==0)
			Execute(argv);
		else
			printf("Command not found\n");

		Initialize(buf,argv);
	}
}

int DivideCommand(char *buf, char **argv, char **path)
{
	int i,j,k;
	char tmp[BUFSIZ];

	for(i=0, j=0, k=0; buf[i] ; i++)
	{
		if(buf[i]==' ' || buf[i]=='\n')
		{
			argv[k]=malloc(strlen(tmp));
			strcpy(argv[k],tmp);
			k++;
			j=0;
			memset(tmp,0,sizeof(tmp));
		}
		else
			tmp[j++]=buf[i];
	}

	for(i=0; i<2; i++)
	{
		memset(tmp,0,sizeof(tmp));
		sprintf(tmp,"%s/%s",path[i],argv[0]);
		memset(argv[0],0,sizeof(argv[0]));
		strcpy(argv[0],tmp);

		if(access(argv[0],F_OK)==0)
			return 0;
	}

	return -1;
}

void Execute(char **argv)
{
	char buf[BUFSIZ];
	int server_fd, client_fd, size;

	if((server_fd=open("SERVER",O_WRONLY))<0)
	{
		perror("server open ");
		exit(1);
	}

	if(fork()==0)
	{
		close(1);
		dup(server_fd);
		close(server_fd);

		execv(argv[0],argv);
		perror("execv ");
		exit(0);
	}


	if((client_fd=open("CLIENT",O_RDONLY))<0)
	{
		perror("client open ");
		close(server_fd);
		exit(2);
	}

	while((size=read(client_fd,buf,sizeof(buf)))>0)
		write(1,buf,size);

	
	close(server_fd);
	close(client_fd);	
}

void Initialize(char *buf, char **argv)
{
	int i;

	memset(buf,0,sizeof(buf));
	
	for(i=0; argv[i]; i++)
	{
		memset(argv[i],0,sizeof(argv[i]));
		free(argv[i]);
	}	
}
