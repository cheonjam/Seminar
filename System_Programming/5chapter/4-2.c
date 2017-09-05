#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX 100

void main()
{
	int i, j=0, k, t=0;
	static char str1[MAX], str2[MAX], *argv[MAX];
	static char *path[MAX];

	while(1)
	{
		printf("%%");
		fgets(str1,sizeof(str1),stdin);
		
		/*argv*/
		for(i=0,j=0,k=0; str1[i]!='\n'; i++)
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

		if(!strcmp(argv[0],"setpath")) /* setpath */
		{
			if(argv[1])
			{
				path[t]=malloc(sizeof(argv[1]));
				strcpy(path[t++],argv[1]);
				printf("New path adds\n");
			}
			else
				printf("Incorrect Command (%%setpath pathnamme) \n");
		}
		else if(!strcmp(argv[0],"path")) /* check path */
		{
			for(i=0;i<t;i++)
				printf("%s\n",path[i]);
		}
		else /* fork & exec */
		{
			for(i=0; i<t; i++)
			{
				memset(str2, '\0', sizeof(str2));
				strcpy(str2,path[i]);
				strcat(str2,"/");
				strcat(str2, argv[0]);
				if(!access(str2,F_OK)) 
				{
					if(fork()==0)
						execv(str2,argv); //chil -
					wait((int *)0);
					break;
				}
			}
			if(i==t)
				printf("myShell: %s: command not found...\n",argv[0]);
		}

		/*Initialize*/
		memset(str1,'\0',sizeof(str1));
		memset(str2,'\0',sizeof(str2));
		for(i=0; i<k; i++)
			free(argv[i]);
		memset(argv,0,sizeof(argv));
	}
}

