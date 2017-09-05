#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main()
{
	int fd;
	unlink("qaz");
	fd = open("qaz",O_CREAT|O_RDWR|O_EXCL,0666);
	close(fd);
}
