#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	close(1);
	open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 644);
	printf("Hello, World\n");
}
