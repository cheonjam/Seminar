#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

void main()
{
	char buf[BUFSIZ];
	int read_fd,fd,size;

	mknod("SERVER",S_IFIFO|0666,0);

	while(1)
	{
		memset(buf,0x00,sizeof(buf));
		
		fd=open("SERVER",O_RDONLY);
		read(fd,buf,sizeof(buf));
		close(fd);

		if((fd=open("SERVER",O_WRONLY))<0)
		{
			perror("open2 ");
			continue;
		}


		if((read_fd=open(buf,O_RDONLY))<0)
		{
			perror("open ");
			close(fd);
			continue;
		}

		while((size=read(read_fd,buf,sizeof(buf)))>0)
		{
			write(fd,buf,size);
			memset(buf,0,sizeof(buf));
		}

		close(read_fd);
		close(fd);
	}
}



