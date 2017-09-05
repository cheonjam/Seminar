#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	int fd, read_size;
	char buf[BUFSIZ];

	fd=open("SERVER",O_WRONLY);
	write(fd,argv[1],strlen(argv[1]));
	close(fd);

	fd=open("SERVER",O_RDONLY);

	while((read_size=read(fd,buf,sizeof(buf)))>0)
	{
		write(1,buf,read_size);
		memset(buf,0x00,sizeof(buf));
	}
	close(fd);
}
