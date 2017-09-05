#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	static char *new_argv[] =
	{
		"new_program",
		"param_1",
		"param_2",
		(char *)NULL
	};

	static char *new_envp[] =
	{
//		"USER=TESTER",
//		"HOME=/TEST_DIR",
//		"TESTSTRING=execle() test"
	};

	printf("execve() test program!!!\n");

	execve("./default_envp", new_argv, new_envp);

	perror("execve() :");
	exit(0);
}
