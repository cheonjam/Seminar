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

	printf("execv() test program!!\n");

	execv("./default_envp", new_argv);

	perror("execv() : ");
	exit(0);
}
