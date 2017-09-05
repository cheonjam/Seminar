#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	
	int pid=0, ppid=0;

	if( (pid = fork()) == -1)
	{
		perror("fork() : ");
		exit(-1);
	}

	if( pid == 0 ) // Child Process
	{
		pid = getpid();
		ppid = getppid();
		printf("[Child]Process ID: %d, \t Parent Process ID: %d\n",pid,ppid);
		exit(0);
	} 
	else // Parent Process
	{
		pid = getpid();
		ppid = getppid();
		printf("[Parent]Process ID: %d, \tParent Process ID: %d\n",pid,ppid);
	}
	exit(0);
}
