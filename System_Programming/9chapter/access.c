#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define READABLE 4
#define WRITEABLE 2
#define EXCUTABLE 1
#define EXISTENCE 0

void main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(1);
	}

	if(access(argv[1], EXISTENCE) == -1)
		perror("EXISTENCE : ");
	else
		fprintf(stderr,"EXISTENCE : OK!!\n");

	if(access(argv[1], EXCUTABLE) == -1)
		perror("EXCUTABLE : ");
	else
		fprintf(stderr,"EXCUTABLE : OK!!\n");

	if(access(argv[1], WRITEABLE) == -1)
		perror("WRITEABLE : ");
	else
		fprintf(stderr,"WRITEABLE : OK!!\n");

	if(access(argv[1], READABLE) == -1)
		perror("READABLE : ");
	else
		fprintf(stderr,"READABLE : OK!!\n");

	if(access(argv[1], R_OK) == -1)
		perror("READABLE : ");
	else
		fprintf(stderr,"!!!!READABLE : OK!!\n");
	exit(0);
}
