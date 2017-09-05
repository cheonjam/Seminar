#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd;
	char buf[5];

	 fd = open("./readtest",O_RDONLY);

	if(fd==-1)
		printf("file open error\n");

	while(read(fd, buf, sizeof(buf)))
	{
		printf("[%s]",buf);
		memset(buf,'\0',sizeof(buf));
	}

	close(fd);

}
