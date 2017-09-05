#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main()
{
	int fd, flags;
	int i, n;
	char line[BUFSIZ];

	if( (fd = open("/dev/tty",O_RDONLY | O_NDELAY)) == -1)
	{
		perror("/dev/tty");
		exit(2);
	}

	printf("Enter you PIN within five seconds:\n");
	sleep(5);
	if(read(fd,line,BUFSIZ) <= 0)
	{
		printf("\n=====> Sorry. \n");
		exit(1);
	}

	flags = fcntl(fd, F_GETFL, 0);
	flags &= ~O_NDELAY;
	fcntl(fd, F_SETFL, flags);

	printf("enter you bank account number:\n");
	i = read(fd, line, BUFSIZ);
	line[i]='\0';
	printf("%s\n",line);
}
