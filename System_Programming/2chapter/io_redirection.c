#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char **argv)
{
	close(1);
	if(open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644) < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	close(2);
	if(dup(1) < 0)
	{
		perror(argv[0]);
		exit(2);
	}
	printf("1: stdout----");
	fprintf(stderr,"2: stdout----");
	printf("3: stdout----");
	fprintf(stderr,"4: stdout----");
/*
	printf("1: stdout----\n");
	fprintf(stderr,"2: stdout----\n");
	printf("3: stdout----\n");
	fprintf(stderr,"4: stdout----\n");
	*/
}

