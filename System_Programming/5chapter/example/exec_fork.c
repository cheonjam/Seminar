#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int fork();

	if(fork() == 0)
	{
		execl("/bin/echo", "echo","this is","message one",(char *)NULL);
		perror("exec one failed");
		exit(1);
	}

	if(fork() == 0) 
	{
		execl("/bin/echo", "echo","this is","message two",(char *)NULL);
		perror("exec two failed");
		exit(2);
	}

	if(fork() == 0) 
	{
		execl("/bin/echo", "echo","this is","message three",(char *)NULL);
		perror("exec three failed");
		exit(3);
	}

	printf("parent program ending\n");
}
	
