#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	printf("execlp() test program!!!\n");

	execlp("./default_envp", "new_program", "param_1", "param_2", (char *)0);

	perror("execlp() : ");
	exit(0);
}
