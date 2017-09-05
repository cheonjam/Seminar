#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	printf("execl() test program!!\n");
	execl("./default_envp", "new_program","param_1","param_2",(char *)NULL);

	perror("execl() : ");
	exit(0);
}
