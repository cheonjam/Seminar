#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX 100

int Save_Argv(char *str1, char *str2, char **argv);
void Fork_Exec(char **path, char **argv);
void Initialize(char *str1, char *str2, char **argv, int argv_count);

void main()
{
	int argv_count;
	static char str1[MAX], str2[MAX], *argv[MAX];
	static char *path[3]={"/bin/","/usr/bin/","/usr/local/bin/"};
	while(1)
	{
		printf("%%");
		fgets(str1,sizeof(str1),stdin);
	 
		argv_count=Save_Argv(str1, str2, argv); // This function stores your input in an argument arrangement.
		Fork_Exec(path,argv); // This function makes child process and executes other process.
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

void Fork_Exec(char **path, char **argv)
{
	int i;
	char str[MAX];

	for(i=0; i<3; i++)
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
	if(i==3)
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
