#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>

#define MAX 100

#define ALL 1
#define LONG 2
#define iNODE 4
#define NUMERIC 8 
#define GROUP 16 

#define GREEN 1
#define BLUE 2
#define BLUE_GREEN 3

typedef struct _information
{
	char mode[11];
	int nlink;
	char uid[256];
	char gid[256];
	int size;
	int month;
	int day;
	int hour;
	int min;
	char name[256];
	int block;
}information;
	
int argv_seperate(int argc, char **argv, char **file);
void mySort(char **file, int file_count);

void print_list(struct stat *fstat, char *path, char *file_name);
void print_mode(struct stat *fstat, char *mode);
int filter(const struct dirent *info);

void myScandir(char *dir);

information *head;
int option, color, max;

void main(int argc, char *argv[])
{
	struct stat s_buf;
	static char *file[MAX];
	int count, i,j,file_count;

	memset(file,0,sizeof(file));
	if((file_count=argv_seperate(argc,argv,file))==-1)
		return;
	else if(file_count==0)
	{
		file[0]=malloc(2);
		strcpy(file[0],".");
		file_count=1;
	}

	/*error control*/
	for(i=0; i<file_count; i++)
	{
		memset(&s_buf,0,sizeof(s_buf));
		if(lstat(file[i],&s_buf)==-1)
			printf("ls: '%s'에 접근할 수 없습니다: 그런 파일이나 디렉터리가 없습니다\n",file[i]);
	}

	mySort(file,file_count);

	/*file print*/
	for(i=0; i<file_count; i++)
	{
		if(lstat(file[i], &s_buf)==-1)
			continue;
		if((s_buf.st_mode & S_IFMT)!=S_IFDIR)
			print_list(&s_buf, file[i], file[i]);
	}
	
	/*directory print*/
	for(i=0; i<file_count; i++)
	{
		if(lstat(file[i], &s_buf)==-1)
			continue;
		if((s_buf.st_mode & S_IFMT)==S_IFDIR)
		{
			if(file_count>1)
				printf("%s:\n",file[i]);
			myScandir(file[i]);
			printf("\n");
		}
	}
	
}

void mySort(char **file, int file_count)
{
	int i,j;
	char *tmp;

	for(i=file_count-1; i>=0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(strcmp(file[j],file[j+1])>0)
			{
				tmp=file[j];
				file[j]=file[j+1];
				file[j+1]=tmp;
			}
		}
	}
}

void myScandir(char *dir)
{
	char name[256];
	struct dirent **namelist;
	struct stat s_buf;
	int i, count, max=0;

	if(option&ALL)
		count = scandir(dir, &namelist, NULL, alphasort);
	else
		count = scandir(dir, &namelist, filter, alphasort);

	for(i=0; i<count; i++)
	{
		sprintf(name,"%s/%s",dir,namelist[i]->d_name);
		lstat(name, &s_buf);
		max+=(s_buf.st_blocks)/2;
	}
	if(option&LONG || option&NUMERIC || option&GROUP)
		printf("합계 %d\n",max);

	for(i=0; i<count; i++)
	{
		memset(name,0,sizeof(name));
		sprintf(name,"%s/%s",dir,namelist[i]->d_name);
		lstat(name, &s_buf);
		
		print_list(&s_buf, name, namelist[i]->d_name);

		free(namelist[i]);
	}
	free(namelist);

}

int argv_seperate(int argc, char **argv, char **file)
{
	int i,j,k=0;
	char **ptr=file;

	for(i=1; i<argc ; i++)
	{
		if(argv[i][0]=='-') // optioin
		{
			for(j=1; j<strlen(argv[i]); j++)
			{
				switch(argv[i][j])
				{
					case 'a' : 
						option|=ALL;
						break;

					case 'l' :
						option|=LONG;
						break;

					case 'i' :
						option|=iNODE;
						break;

					case 'n' :
						option|=NUMERIC;
						break;

					case 'g' :
						option|=GROUP;
						break;

					default :
						printf("ls: Incorrect option --'%c'\n",argv[i][j]);
						return -1;
				}
			}

		}
		else //file or directory
			file[k++]=argv[i];
	}

	return k;

}
	
int filter(const struct dirent *info)
{
	if(info->d_name[0]=='.')
		return 0;
	else
		return 1;
}

void print_list(struct stat *f_buf,char *path,  char *file_name)
{
	char mode[11], link_name[256];

	print_mode(f_buf,mode);
	if(option&iNODE)
		printf("%ld ",f_buf->st_ino);

	if(option&LONG || option&NUMERIC || option&GROUP)
	{
		printf("%s",mode);
		printf(" %2ld ",f_buf->st_nlink);
		if(option&NUMERIC)
		{
			if(!(option&GROUP))
				printf("%d ",f_buf->st_uid);
			printf("%d ",f_buf->st_gid);
			
		}
		else
		{
			if(!(option&GROUP))
				printf("%s ",getpwuid(f_buf->st_uid)->pw_name);
			printf("%s ",getgrgid(f_buf->st_gid)->gr_name);
		}
		printf("%5ld ",f_buf->st_size);
		printf(" %d월 ",localtime(&f_buf->st_mtime)->tm_mon+1);
		printf("%2d ",localtime(&f_buf->st_mtime)->tm_mday);
		printf("%02d:",localtime(&f_buf->st_mtime)->tm_hour);
		printf("%02d ",localtime(&f_buf->st_mtime)->tm_min);
	}

	if(color==0)
		printf("%s",file_name);
	else
	{
		if(color==GREEN)
		{
			printf("\033[0;32m");
			printf("%s\033[0m",file_name);
			printf("*");
		}
		else if(color==BLUE)
		{
			printf("\033[0;34m");
			printf("%s\033[0m",file_name);
			printf("/");
		}
		else if(color==BLUE_GREEN)
		{
			printf("\033[0;36m");
			printf("%s\033[0m",file_name);
			readlink(path, link_name, 256);
			if(option&LONG)
				printf(" -> %s",link_name);
		}
		color=0;
	}

		printf("\n");
}

void print_mode(struct stat *f_buf, char *mode)
{
	switch(f_buf->st_mode & S_IFMT)
	{
		case S_IFDIR :
			color=BLUE;
			strcpy(mode,"d");
			break;
		case S_IFCHR :
			strcpy(mode,"c");
			break;

		case S_IFBLK :
			strcpy(mode,"b");
			break;

		case S_IFREG :
			strcpy(mode,"-");
			break;

		case S_IFIFO :
			strcpy(mode,"p");
			break;

		case S_IFLNK :
			color=BLUE_GREEN;
			strcpy(mode,"l");
			break;

		case S_IFSOCK :
			strcpy(mode,"s");
			break;
	}

	if(f_buf->st_mode & S_IRUSR )
		strcat(mode,"r");
	else
		strcat(mode,"-");
	
	if(f_buf->st_mode & S_IWUSR )
		strcat(mode,"w");
	else
		strcat(mode,"-");

	if(f_buf->st_mode & S_IXUSR )
	{
		if(color==0)
			color=GREEN;
		strcat(mode,"x");
	}
	else
		strcat(mode,"-");

	if(f_buf->st_mode & S_IRGRP )
		strcat(mode,"r");
	else
		strcat(mode,"-");
	
	if(f_buf->st_mode & S_IWGRP )
		strcat(mode,"w");
	else
		strcat(mode,"-");

	if(f_buf->st_mode & S_IXGRP )
	{
		if(color==0)
			color==GREEN;
		strcat(mode,"x");
	}
	else
		strcat(mode,"-");


	if(f_buf->st_mode & S_IROTH )
		strcat(mode,"r");
	else
		strcat(mode,"-");
	
	if(f_buf->st_mode & S_IWOTH )
		strcat(mode,"w");
	else
		strcat(mode,"-");

	if(f_buf->st_mode & S_IXOTH )
	{
		if(color==0)
			color==GREEN;
		strcat(mode,"x");
	}
	else
		strcat(mode,"-");
}

