#include <stdio.h>
#include <unistd.h>

void main()
{
	alarm(1);
	pause();
	fprintf(stderr,"good\n");
}
