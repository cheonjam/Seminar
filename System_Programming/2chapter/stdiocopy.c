#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLENGTH 10

void main() 
{
	char buf[MAXLENGTH];
	int size=0;

	while( (size = read(0, buf, MAXLENGTH)) > 0 )
	{
		write(1, buf, size);
		memset(buf, 0x00, MAXLENGTH);
	}
	
	exit(0);
}
