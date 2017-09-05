#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	static char *new_envp[] =
	{
		"USER=TESTER",
		"HOME=/TEST_DIR",
		"TESTSTRING=execle() test"
	};

	printf("execle() test program!!!\n");

	execle("./default_envp", "new_program","param_1","param_2",
					(char *)NULL, new_envp);

	perror("execle() :");
	exit(0);
}
