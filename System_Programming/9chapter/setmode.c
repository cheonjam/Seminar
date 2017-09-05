#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

void main(int argc, char *argv[])
{
	int new_mode;

	new_mode = strtol(argv[1], (char **)NULL, 8);

	if( chmod(argv[2],new_mode)==-1 )
	{
		perror(argv[2]);
		exit(1);
	}

	exit(0);
}
