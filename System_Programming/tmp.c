#include <stdio.h>

int Check_Syntax(char **argv, char **tmp)
{
	static int i=-1;

	++i;
	
	switch(*argv[i])
	{
		case ';' : 
			return 1;


		case '|' :
			return 2;


		case '&' :
			return 3;

		case '>' :
			return 4;
	
		default :
			tmp=argv;
			for(;*argv[i];i++)
				;	
			return 5;
	}
}

void Fork_Exec(char **path, char **argv)
{
	int i,j=0;
	char str[MAX], **tmp;

	for(i=0; i<path_count; i++)
	{
		memset(str, '\0', sizeof(str));
		sprintf(str, 

	
