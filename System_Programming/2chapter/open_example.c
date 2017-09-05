#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *pathname1 = "/tmp/testfile";
	char *pathname2 = "currnetfile";
	int fd;

	printf("%d\n",fd=open(pathname2, O_RDONLY));
	printf("%d\n",fd=open(pathname1, O_WRONLY|O_CREAT|O_APPEND,0600));
	printf("%d\n",fd=open(argv[1],O_RDWR));
	if((fd=open(pathname1,O_WRONLY|O_CREAT|O_EXCL,0666))==-1)
		perror(pathname1);
}

