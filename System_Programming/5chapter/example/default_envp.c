#include <stdio.h>

extern char **environ;

void main(int argc ,char *argv[])
{
	char **ptr;
	int index=0;

	for(index=0; index < argc ; index++)
		printf("argv[%d] : %s\n", index, argv[index]);

	printf("Environment Variableds\n");
	for(ptr=environ, index=0; *ptr!=(char *)NULL; ptr++, index++)
		printf("environ[%d] : %s\n", index, *ptr);
}

