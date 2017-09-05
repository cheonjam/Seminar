#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void read2line(char *);

char text[80];

void main(int argc, char **argv)
{
	int fd[2];

	if(pipe(fd) == -1) /* pipe exeption handling */
	{
		perror(argv[0]);
		exit(1);
	}

	if(fork() ==0) /* first child */
	{
		close(1); // close stdout
		dup(fd[1]); // fd[1] -> stdout
		close(fd[0]);
		close(fd[1]);
		printf("ls display sorted\n");
		fflush(stdout);
		execl("/bin/ls","ls","-l",(char *)0);
		exit(127);
	}

	if(fork()==0) /* second child */
	{
		close(0); // close stdin
		dup(fd[0]); // fd[0] -> stdin
		close(fd[0]);
		close(fd[1]);
		read2line(text);
		printf("\t Heading: %s\n",text);
		fflush(stdout);
		execl("/usr/bin/sort","sort","-k","5,5n",(char *)0);
		exit(127);
	}

	close(fd[0]);
	close(fd[1]);
	while(wait((int *)0) != -1)
		;
	exit (0);
}
void read2line(char *input) 
{
	while(1)
	{
		read(0,input,1);
		if(*input=='\n')
			break;
		else
			input++;
	}
}
