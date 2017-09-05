#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	char *new_argv[] = 
	{
	   	"new_program",
	   	"param_1",
	   	"param_2",
	   	(char *)NULL
	};

	printf("execvp() test program!!\n");

	execv("./default_envp", new_argv);
	
	perror("execvp() : ");
	exit(0);
}
