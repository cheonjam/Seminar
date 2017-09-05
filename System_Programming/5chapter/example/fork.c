#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	if(fork() == 0)
			printf("child.\n");
	else
			printf("parent.\n");
	printf("both\n");
//	system("ps");
//	printf("===============\n");
}
