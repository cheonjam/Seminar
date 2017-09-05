#include <stdio.h>

extern char **environ;

void main(int argc, char *argv[])
{
	char **ptr;
	int i=0;

	for(i=0; i<argc; i++)
		printf("argv[%d] : %s\n", i, argv[i]);

	printf("Environment Variables\n");
	for(ptr=environ, i=0; *ptr ; ptr++, i++)
		printf("environ[%d] : %s\n",i,*ptr);
}

