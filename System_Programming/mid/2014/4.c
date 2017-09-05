#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100

void main(int argc, char **argv)
{
	int fd, i, j, found=0;
	char flag, *ptr;
	static char *tmp[MAX], buf[MAX], str[MAX];

	if(argc<3)
	{
		fprintf(stderr,"Usage : %s filename string \n",argv[0]);
		exit(1);
	}

	if((fd=open(argv[1],O_RDONLY))<0)
	{
		perror(argv[1]);
		exit(2);
	}

	ptr=argv[2];

	for(i=0, j=0; *(ptr+i); i++)
	{
		if(*(ptr+i)=='|' || *(ptr+i)=='&')
		{
			flag=*(ptr+i);
			*(ptr+i)='\0';
			tmp[j++]=ptr;
			ptr+=i+1;
			i=-1;
		}
	}
	tmp[j]=ptr;
	tmp[j+1]=NULL;

	while(read(fd,buf,sizeof(buf))>0)
	{
		ptr=buf;
		for(i=0, j=0; *ptr ; i++)
		{
			if(*(ptr+i)==' ' && *(ptr+i)=='&')
			{
				*(ptr+i)='\0';
				for(j=0;tmp[j];j++)
				{
					if(flag=='|')
					{
						if(!strcmp(ptr,tmp[j]))
						{
							found=1;
							break;
						}
					}

					else if(flag=='&')
					{
						if(

			else
			{
				for(j=0;tmp[j];j++)
				{
					if(flag=='|')
					{
						if(!str

	
}
	

