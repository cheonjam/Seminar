#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#define MAX BUFSIZ

#define F_OK 0
#define NORMAL 1
#define BG 2
#define PIPE 3
#define PIPE_ON 4
#define R_REDIR 5
#define L_REDIR 6

int Save_Argv(char *input, char *tmp, char **argv);
void Initialize(char *input, char *tmp, char **argv);
void Setpath(char **path, char **argv);
void Read_Path(char **path);

void Check_Syntax(char **path, char **argv);
int myaccess(char **path, char **argv, char *str, int flag);

int Fork_Exec(char **path, char **argv);
void Pipe_handling(int *prev_fd, int *new_fd);
void pipe_make(int *new_fd);
void status_handling(int *prev_fd, int *new_fd);

void Redir_handling(char *filename, int *fd);

int argv_count, path_count, status, prev_status;


void main()
{
	int i;
	static char input[MAX], tmp[MAX], *argv[MAX];
	static char *path[MAX];

	status=NORMAL;

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
		for(i=0 ; i<argv_count; i++)
			fprintf(stderr,"[%d]%s ",i,argv[i]);
		fprintf(stderr,"\n");

		if(argv_count==0)
			continue;
		else if(!strcmp(argv[0],"exit"))
			exit(0);
		else if(!strcmp(argv[0],"setpath"))
			Setpath(path, argv); //If you enter "setpath", your input adds new path
		else if(!strcmp(argv[0],"cd"))
		{
			if(chdir(argv[1])==-1)
				perror(argv[1]);
		}
		else
			Check_Syntax(path, argv);
		Initialize(input, tmp, argv);
	}
}

void Check_Syntax(char **path, char **argv)
{
	int count=0, i;

	for(i=count; count<argv_count; count++)
	{
		if(argv[count]==NULL)
			continue;

		if(!strcmp(argv[count],";"))
		{  
			if(Fork_Exec(path,&argv[i])==-1)
				break;
			i=count+1;
		}
		else if(!strcmp(argv[count],"&"))
		{
			prev_status=status;
			status=BG;
			if(Fork_Exec(path,&argv[i])==-1)
				break;
			i=count+1;
			status=NORMAL;
		}
		else if(!strcmp(argv[count],"|"))
		{
			prev_status=status;
			status=PIPE;
			if(Fork_Exec(path,&argv[i])==-1)
				break;
			i=count+1;
			status=PIPE_ON;
		}
		else if(!strcmp(argv[count],">"))
		{
			prev_status=status;
			status=R_REDIR;
			if(Fork_Exec(path,&argv[i])==-1)
				break;
			i=count+1;
		}
		else if(!strcmp(argv[count],"<"))
		{

		}
	}

	if(count==argv_count)
	{
		prev_status=status;
		if(!strcmp(argv[count-1],";"))
			return ;
		else if(!strcmp(argv[count-1],"&"))
			return ;
		else if(!strcmp(argv[count-1],"|"))
			fprintf(stderr,"Syntax error '|'\n");
		else if(!strcmp(argv[count-1],"<"))
			fprintf(stderr,"Syntax error '<'\n");
		else if(!strcmp(argv[count-1],">"))
			fprintf(stderr,"Syntax error '>'\n");
		else
			Fork_Exec(path,&argv[i]);
	}
}

int myaccess(char **path, char **argv, char *str, int flag)
{
	int i;

	if(prev_status==R_REDIR)
		return 0;

	for(i=0; i<path_count; i++)
	{
		memset(str, '\0', sizeof(str));
		sprintf(str,"%s%s",path[i],*argv);

		if(!access(str,flag))
			return 0;
	}

	printf("MyShell: %s: command not found...\n",argv[0]);
	sleep(1);
	return -1;
}


int Fork_Exec(char **path, char **argv)
{
	char str[MAX];
	int pid, fd1[2], fd2[2];
	static int *prev_fd, *new_fd;
	
	if(myaccess(path, argv, str, F_OK)==-1)
		return -1;
	
	printf("str : %s\n",str);
	if(status==PIPE || status==R_REDIR)
	{
		if(new_fd==0 || new_fd==fd2)
			new_fd=fd1;
		else
			new_fd=fd2;
		pipe_make(new_fd);
	}

	if((pid=fork())==0)
	{
		Pipe_handling(prev_fd,new_fd);
		if(prev_status==R_REDIR)
			Redir_handling(argv[0],prev_fd);
		else
		{

			execv(str,argv);
			perror("execv()");
			exit(-1);
		}
	}

	status_handling(prev_fd, new_fd);

	if(status!=BG)
		while(wait((int *)0)!=pid);

	
	prev_fd=new_fd;
	return 0;
}

void pipe_make(int *new_fd)
{
	if(pipe(new_fd)==-1)
	{
		perror("new_pipe : ");
		exit(-1);
	}
}

void Pipe_handling(int *prev_fd, int *new_fd)
{
	if(status==PIPE || status==R_REDIR)
	{
		close(1);
		dup(new_fd[1]);
		close(new_fd[0]);
		close(new_fd[1]);
	}

	if(prev_status==PIPE_ON)
	{
		close(0);
		dup(prev_fd[0]);
		close(prev_fd[0]);
		close(prev_fd[1]);
	}
}

void status_handling(int *prev_fd, int *new_fd)
{
	switch(status)
	{
		case PIPE :
			if(prev_status==PIPE_ON)
			{
				close(prev_fd[0]);
				close(new_fd[1]);
			}
			else
				close(new_fd[1]);
			break;

		case PIPE_ON :
			close(prev_fd[0]);
			status=NORMAL;
			break;

			
		case R_REDIR :
			if(prev_status==PIPE_ON)
			{
				close(prev_fd[1]);
				close(new_fd[0]);
			}
			close(new_fd[1]);
			break;
			
	}
}
void Redir_handling(char *filename, int *fd)
{
	int file_fd, size;
	char buf[MAX], tmp[MAX];

	if( (file_fd=open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
	{
		perror(filename);
		close(file_fd);
	}

	while( (size=read(fd[0],buf,MAX))>0 )
	{
		fprintf(stderr,"good\n");
		write(file_fd, buf, size);
	}

	fprintf(stderr,"bad\n");
	close(fd[0]);
	close(file_fd);
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
	int i, j, k;

	for(i=0, j=0, k=0; input[i]!='\n' ; i++)
	{
		if(input[i]=='|' || input[i]==';' || input[i]=='&' || input[i]=='>') 
		{
			if(*tmp)
			{
				argv[k]=malloc(strlen(tmp)+1);
				strcpy(argv[k++],tmp);
				j=0;
				memset(tmp,'\0',sizeof(tmp));
			}
			argv[k++] = NULL;
			argv[k]=malloc(2);
			sprintf(argv[k++],"%c",input[i]);
		}
		else if(input[i]!=' ')
			tmp[j++]=input[i];
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

}


void Initialize(char *input, char *tmp, char **argv)
{
	int i;

	memset(input,'\0',sizeof(input));
	memset(tmp,'\0',sizeof(tmp));
	for(i=0; i<argv_count; i++)
	{
		if(argv[i]==NULL)
			continue;
		memset(argv[i],'\0',sizeof(argv[i]));
		free(argv[i]);
	}
	memset(argv,0,sizeof(argv));
	argv_count=0;
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
	strcpy(path[path_count++],argv[1]);

	printf("\033[33m\"%s\" added.\033[0m \n",argv[1]);
}
	
