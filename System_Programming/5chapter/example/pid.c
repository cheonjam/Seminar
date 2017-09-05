#include <stdio.h>
#include <sys/types.h>
#include <sys/unistd.h>

void main()
{
	printf("pid=[%d]\n",getpid());
	printf("ppid=[%d]\n\n",getppid());

	
	printf("uid=[%d]\n",getuid());
	printf("euid=[%d]\n\n",geteuid());

	seteuid(500);
	printf("uid=[%d]\n",getuid());
	printf("euid=[%d]\n\n",geteuid());

	printf("gid=[%d]\n",getgid());
	printf("egid=[%d]\n",getegid());
}
