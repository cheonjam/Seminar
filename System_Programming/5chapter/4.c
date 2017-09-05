#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX 100

int Save_Argv(char *str1, char *str2, char **argv);
void Fork_Exec(char **path, char **argv, int path_count);
void Initialize(char *str1, char *str2, char **argv, int argv_count);
void Setpath(char **path, char **argv, int *count);

void main()
{
	int argv_count, path_count=0;
	static char str1[MAX], str2[MAX], *argv[MAX];
	static char *path[MAX];
	while(1)
	{
		printf("%%");
		fgets(str1,sizeof(str1),stdin);
	 
		argv_count=Save_Argv(str1, str2, argv); // This function stores your input in an argument arrangement.
		if(!strcmp(argv[0],"setpath"))
			Setpath(path, argv, &path_count); //If you enter "setpath", your input adds new path
		else	
			Fork_Exec(path,argv, path_count); // This function makes child process and executes other process.
		Initialize(str1, str2, argv, argv_count);
	}
}

int Save_Argv(char *str1, char *str2, char **argv)
{
	int i, j, k;

	for(i=0, j=0, k=0; str1[i]!='\n' ; i++)
	{
		if(str1[i]!=' ')
			str2[j++]=str1[i];
		else if(str1[i]==' ' && j!=0)
		{
			str2[j]='\0';
			argv[k]=malloc(sizeof(str2));
			strcpy(argv[k++],str2);
			j=0;
			memset(str2,'\0',sizeof(str2));
		}
	}

	str2[j]='\0';
	argv[k]=malloc(sizeof(str2));
	strcpy(argv[k++],str2);
	argv[k]=NULL;
	
	return k;
}

void Fork_Exec(char **path, char **argv, int path_count)
{
	int i;
	char str[MAX];

	for(i=0; i<path_count; i++)
	{
		memset(str, '\0', sizeof(str));
		strcpy(str, path[i]);
		strcat(str, argv[0]);
		
		if(!access(str,F_OK))
		{
			if(fork()==0)
				execv(str,argv);
			while(wait((int *)0)!=-1)
				;
			break;
		}
	}
	if(i==path_count)
		printf("MyShell: %s: command not found...\n",argv[0]);
}

void Initialize(char *str1, char *str2, char **argv, int argv_count)
{
	int i;

	memset(str1,'\0',sizeof(str1));
	memset(str2,'\0',sizeof(str2));
	for(i=0; i<argv_count; i++)
		free(argv[i]);
	memset(argv,0,sizeof(argv));
}

void Setpath(char **path, char **argv, int *count)
{
	if(!argv[1]) // argv[1] == NULL
	{
		printf("Incorrect Command(%%setpath path_name)\n");
		return ;
	}

	strcat(argv[1],"/");
	path[*count]=malloc(sizeof(argv[1]));
	strcpy(path[(*count)++],argv[1]);
	printf("\033[33m\"%s\" added.\033[0m \n",argv[1]);
}
	
