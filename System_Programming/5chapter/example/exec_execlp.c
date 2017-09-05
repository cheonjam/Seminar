#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	printf("execlp() test program!!\n");

	execlp("./default_envp", "new_program","param_1","param_2",(char *)NULL);

	perror("execl() : ");
	exit(0);
}
