#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd1,fd2,fd3,fd4;

	fd1=open("test.txt",O_CREAT);
	fd2=open("test.txt",O_RDONLY);
	fd3=open("test.txt",O_RDONLY);

	printf("file descriptor1 : %d\n",fd1);
	printf("file descriptor2 : %d\n",fd2);
	printf("file descriptor3 : %d\n",fd3);

	close(fd1);


	fd4=open("test.txt",O_RDONLY);
	printf("file descriptor4 : %d\n",fd4);
	printf("file descriptor2 : %d\n",fd2);
	printf("file descriptor3 : %d\n",fd3);
	close(fd4);
	close(fd2);
	close(fd3);
}
