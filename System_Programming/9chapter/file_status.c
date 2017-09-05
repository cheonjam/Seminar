#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char p_name[20];

void print_stauts(struct stat*);
void print_mode(struct stat*);

void main(int argc, char *argv[])
{
	struct stat s_buf;

	if(stat(argv[1], &s_buf)==-1)
	{
		perror(argv[1]);
		exit(1);
	}

	memcpy(p_name, argv[1], strlen(argv[1]));
	p_name[strlen(argv[1])]='\0';
	print_stauts(&s_buf);
}

void print_stauts(struct stat *f_buf)
{
	printf("file name : %s\n",p_name);
	printf("device id : %ld\n",f_buf->st_dev);
	printf("i-node number : %ld\n",f_buf->st_ino);
	print_mode(f_buf);
	printf("linkds : %ld\n",f_buf->st_nlink);
	printf("file size : %ld\n",f_buf->st_size);
}

void print_mode(struct stat *f_buf)
{
	switch(f_buf->st_mode & S_IFMT)
	{
		case S_IFDIR :
			printf("Directory!!\n");
			break;
		case S_IFCHR :
			printf("Character Device  File,\t Device Number : %ld\n",f_buf->st_rdev);
			break;

		case S_IFBLK :
			printf("Block Device File,\t Device Number : %ld\n",f_buf->st_rdev);
			break;

		case S_IFREG :
			printf("Regular File\n");
			break;

		case S_IFIFO :
			printf("Named pipes\n");
			break;
	}

	if(f_buf->st_mode & S_ISUID)
		printf("Set UID\n");
	if(f_buf->st_mode & S_ISGID)
		printf("Seg GID\n");

	printf("Permission : %o\n",f_buf->st_mode & 0777);
}

