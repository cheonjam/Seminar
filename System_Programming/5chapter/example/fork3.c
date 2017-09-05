#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BIGNUMBER	100000000

void main(int argc, char *argv[])
{
	char ch, first, last;
	int pid, i;

	if((pid=fork())>0)
	{
		first='A';
		last='Z';
	}
	else if(pid==0)
	{
		first='a';
		last='z';
	}
	else
	{
		perror(argv[0]);
		exit(1);
	}

	for(ch=first; ch<=last;ch++)
	{
		for(i=0; i<BIGNUMBER; i++)
			;
		write(1,&ch,1);
	}

	write(1,"\n",1);

	exit(0);
}

