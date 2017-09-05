#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX 100

void Save_Argv(char *str1, char *str2, char **argv);
void main()
{
	int i, j=0, k;
	static char str1[MAX], str2[MAX], *argv[MAX];
	static char *path[3]={"/bin/","/usr/bin/","/usr/local/bin/"};

	while(1)
	{
		printf("%%");
		fgets(str1,sizeof(str1),stdin);

		Save_Argv(str1, str2, argv);

		/* fork & exec */
		for(i=0; i<3; i++)
		{
			memset(str2, '\0', sizeof(str2));
			strcpy(str2,path[i]);
			strcat(str2, argv[0]);
			if(!access(str2,F_OK)) 
			{
				if(fork()==0)
					execv(str2,argv);
				wait((int *)0);
				break;
			}
		}
		if(i==3)
			printf("Command not found\n");

		/*Initialize*/
		memset(str1,'\0',sizeof(str1));
		memset(str2,'\0',sizeof(str2));
		for(i=0; i<k; i++)
			free(argv[i]);
		memset(argv,0,sizeof(argv));
	}
}

void Save_Argv(char *str1, char *str2, char **argv)
{
	int i, j, k;

	for(i=0, j=0, k=0; str[i]!='\n' ; i++)
	{
		if(str[i]!=' ')
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
}

/* logout exit a.out*/
