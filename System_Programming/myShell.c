#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#define MAX BUFSIZ

int Save_Argv(char *input, char *tmp, char **argv);
void Fork_Exec(char **path, char **argv);
void Initialize(char *input, char *tmp, char **argv);
void Setpath(char **path, char **argv);
void Read_Path(char **path);

int argv_count, path_count;

void main()
{
	int i;
	static char input[MAX], tmp[MAX], *argv[MAX];
	static char *path[MAX];

//	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

	Read_Path(path);

	while(1)
	{
		fprintf(stderr,"%% ");
		read(0,input,sizeof(input));
	
		argv_count=Save_Argv(input, tmp, argv); //This function stores your input in an argument arrangement.

		fprintf(stderr,"argv : ");
		for(i=0 ; i<=argv_count; i++)
			fprintf(stderr,"[%d]%s ",i,argv[i]);
		fprintf(stderr,"\n");

		if(argv_count==0)
			continue;
		else if(!strcmp(argv[0],"exit"))
			exit(0);
		else if(!strcmp(argv[0],"setpath"))
			Setpath(path, argv); //If you enter "setpath", your input adds new path
		else
			Fork_Exec(path,argv); //This function makes child process and executes other process.
		Initialize(input, tmp, argv);
	}
}

void Read_Path(char **path)
{
	int fd, i=0;
	char buf, *home;
	static char	tmp[MAX];

	home=getenv("HOME");
	sprintf(tmp,"%s/.myShellRc",home);

	if( (fd=open(tmp,O_RDONLY)) < 0)
	{
		perror("~/.myShellRc");
		exit(1);
	}
	memset(tmp,0,sizeof(tmp));
	
	
	while(1)
	{
		if(!read(fd,&buf,1))
			break;

		if(buf!=':' && buf!='\n')
			tmp[i++]=buf;
		else 
		{
			if(tmp[i=1]!='/')
				sprintf(tmp,"%s/",tmp);
			path[path_count]=malloc(strlen(tmp)+1);
			strcpy(path[path_count++],tmp);
			memset(tmp,'\0',sizeof(tmp));
			i=0;
		}
	}
}

int Save_Argv(char *input, char *tmp, char **argv)
{

	int num=0,cur=0,flag=0;

	while(input[cur]!='\0')
	{
		if(input[cur]!= ' ' && flag==0)
		{
			argv[num++]=&input[cur];
			flag=1;
		}
		else if( (input[cur]==' ' || input[cur]=='\n') && flag==1 )
		{
			input[cur]='\0';
			flag=0;
		}
		cur++;
	}
	return num;
	
/*
	int i, j, k;

	for(i=0, j=0, k=0; input[i]!='\n' ; i++)
	{
		if(input[i]=='|' || input[i]==';' || input[i]=='&' || input[i]=='>') 
		{
			printf("%c, j:%d\n",input[i],j);
			if(j!=0)
				argv[k++] = NULL;
			argv[k]=malloc(2);
			sprintf(argv[k++],"%c",input[i]);
			argv[k++] = NULL;
		}
		else if(input[i]!=' ')
		{
			tmp[j++]=input[i];
			printf("/j : %d\n",j);
		}
						
		else if(input[i]==' ' && j!=0)
		{
			argv[k]=malloc(strlen(tmp)+1);
			strcpy(argv[k++],tmp);
			j=0;
			memset(tmp,'\0',sizeof(tmp));
		}
	}
	
	if(j!=0)
	{
		argv[k]=malloc(strlen(tmp)+1);
		strcpy(argv[k++],tmp);
		argv[k]=NULL;
	}

	return k;
*/
}
/*
int Check_Syntax(char **argv)
{
	static int count=0;

	for(;argv[j];j++)
		;
	if(j>=argv_count)
		return -1;
	return ++j;
}
*/
void Fork_Exec(char **path, char **argv)
{
	int i,j=0;
	char str[MAX], **tmp;
	
	for(i=0; i<path_count; i++)
	{
		memset(str, '\0', sizeof(str));
		sprintf(str,"%s%s",path[i],argv[j]);
						
		if(!access(str,F_OK))
		{
			if(fork()==0)
			{
				execv(str,argv);
				perror("execv()");
				exit(-1);
			}
			break;
		}
	}

	wait((int *)0);
	if(i==path_count)
	{
		printf("MyShell: %s: command not found...\n",argv[0]);
		sleep(1);
	}
}

void Initialize(char *input, char *tmp, char **argv)
{
	int i;

	memset(input,'\0',sizeof(input));
	memset(tmp,'\0',sizeof(tmp));
	for(i=0; i<argv_count; i++)
	{
		memset(argv[i],'\0',sizeof(argv[i]));
		free(argv[i]);
	}
	memset(argv,0,sizeof(argv));
}

void Setpath(char **path, char **argv)
{
	if(!argv[1] || argv[2] != NULL) // argv[1] == NULL
	{
		printf("Incorrect Command(%%setpath path_name)\n");
		return ;
	}

	if(*(argv[1]+strlen(argv[1])-1)!='/')
		strcat(argv[1]+strlen(argv[1]),"/");

	path[path_count]=malloc(strlen(argv[1])+1);
	strcpy(path[(path_count)++],argv[1]);

	printf("\033[33m\"%s\" added.\033[0m \n",argv[1]);
}
